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
  int n;
  scanf("%d", &n);
  int sculpz[n];
  for(int i = 0; i < n; i++){
    cin >> sculpz[i];
  }
  int best = -111111111;
  for(int i = 1; i*2 < n; i++){
    if(n % i == 0){
      for(int j = 0; j < i; j++){
	int sum = 0;
	for(int k = 0; k*i < n; k++){
	  sum += sculpz[k*i+j];
	}
	//cout << i << " " << sum << endl;
	if(sum >= best){
	  best = sum;
	}
      }
    }
  }
  cout << best << endl;
  exit(0);
}