//195A 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <map>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}

int DEBUG = 0;
main(int argc, char **argv) {
    DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
    int n, m; cin >> n >> m;
    int array[m];
    if(m % 2 == 0){
        for(int i = 0; i < m/2; i++){
            array[2*i] = m/2-1-i;
        }
        for(int i = 0; i < m/2; i++){
            array[2*i + 1] = m/2 + i;
        }
    } else {
        for(int i = 0; i < (m+1)/2; i++){
            array[2*i] = (m-1)/2+i;
        }
        for(int i = 0; i < (m-1)/2; i++){
            array[2*i+1] = (m-3)/2-i;
        }
    }
    for(int i = 0; i < n; i++){
        cout << array[i%m] + 1<< endl;
    }
}