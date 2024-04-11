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
#include <vector>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
    int n;
    cin >> n;
    int stuff[n];
    for(int i = 0; i < n; i++){
    cin >> stuff[i];    
    }
    int k = 0;
    vector<int> folder;
    int numn = 0;
    int a = 0;
    while(k < n){
        numn = 0;
        a = 0;
        while (numn < 3){
            if(k > n){
                break;
            }
            if(stuff[k] < 0){
                if(numn < 2){
                k++;
                a++;
                numn++;
                } else {
                    folder.push_back(a);
                    //cout << k << endl;
                    break;
                    
                }
            } else {
                k++;
                a++;
            }
    
        } 
        
    }
    if(a > 0){
         folder.push_back(a-1);   
    }
    
    cout <<folder.size() << endl;
    for(int i = 0; i < folder.size(); i++){
        cout << folder[i] << " ";
    }
    cout << endl;
}