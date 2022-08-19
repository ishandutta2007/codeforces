#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n, k;
  cin >> n >> k;
  LL a = LL(((k-1)*n)/k);
  LL vk = 0;
  LL b = a;
  for(LL i = 0; i < 34; i++){
    vk += b;
    b = LL(b/k);
  }
  if(vk >= n){
    cout << a << endl;
    exit(0);
  }
  for(LL i = a+1; i <= n; i++){
    LL c = i;
    vk++;
    while(c % k == 0){
      vk++;
      c = c/k;
    }
    if(DEBUG){
      cout << "i=" << i << endl;
    }
    if(vk >= n){
      cout << i << endl;
      exit(0);      
    }
  }

}