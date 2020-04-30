//
// Created by joaquin_ramirez on 4/29/20.
//

#ifndef UVA_FUNCIONES_H
#define UVA_FUNCIONES_H
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>
using namespace std;


void permutacion_string(string palabra){
    string primera = palabra;
    sort(begin(primera), end(primera));
    next_permutation(begin(palabra),end(palabra));
    if(palabra == primera) {
        cout << "No Successor" << endl;
        return;
    }
    cout << palabra;
}
void test_1(){
        string input;
        while(true){
            cin >> input;
            if(input == "#" or input.size()>50)
                break;
            permutacion_string(input);
        }
}

void test_2(){
    int n, L, A[50];
    cin >> n;
    while(n--) {
        cin >> L;
        int i, j, cont = 0, tmp;
        for(i = 0; i < L; i++)
            cin >> A[i];
        for(i = 0; i < L; i++) {
            for(j = L-1; j > i; j--) {
                if(A[j] < A[j-1]) {
                    tmp = A[j];
                    A[j] = A[j-1];
                    A[j-1] = tmp;
                    cont++;
                }
            }
        }
        cout << "Optimal train swapping takes " << cont << " swaps" << endl;
    }
}
void test_3(){
    int t;
    string linea;
    cin >> t;
    getchar();
    while(t--) {
        getchar();
        int idx[5000], n = 1, i = 1;
        string x[5000];
        getline(cin, linea);
        stringstream sin;
        sin << linea;
        while(sin >> idx[n])
            n++;
        getline(cin, linea);
        sin.clear();
        sin << linea;
        while(sin >> x[idx[i]])
            i++;
        for(i = 1; i < n; i++)
            cout << x[i] << endl;
        if(t)
            cout << "";
    }
}
struct algo{
    int F;
    string palabra;

};

int partition(vector<algo>data, int start, int end){
    auto pivot = data[end].F;
    auto pi = start;
    for(int j = start; j < end; j++){
        if(data[j].F >= pivot){
            swap(data[pi], data[j]);
            pi++;
        }
    }
    swap(data[pi], data[end]);
    return pi;
}

void quick_sort(vector<algo> data, int start, int end){
    //condicion inicial
    if(start >= end) return;
    //condicion recursiva
    auto pi = partition(data, start, end);
    quick_sort(data, start, pi - 1);
    quick_sort(data, pi + 1, end);
}



int unsortedness(algo c){
    int con = 0;
    for(int i = 0; i < c.palabra.size() - 1; ++i){
        for(int j = i + 1; j < c.palabra.size();++i){
            if(c.palabra[i] > c.palabra[j])++con;
        }
    }
    return con;
}
void test_4(){
    int cases;
    cin >> cases;
    getchar();
    while(cases--) {
        getchar();
        vector<algo>lista;
        int sizep, total;
        cin >> sizep >> total;
        algo p;
        while(total--){
            cin >> p.palabra;
            p.F = unsortedness(p);
            lista.push_back(p);
        }
        quick_sort(lista, 0,sizep - 1);
        for(auto& elem:lista)
            cout << elem.palabra << endl;
    }

}


#endif //UVA_FUNCIONES_H
