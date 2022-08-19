#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include <set>
using namespace std;
int Max(int a, int b) {
  return (a > b ? a : b);
}

int compare_dec (const void * a, const void * b) {
  if ( *(int*)a < *(int*)b ) return 1;
  if ( *(int*)a > *(int*)b ) return -1;
  return 0;
}
main(int argc, char **argv) {
  int n, m;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  cin >> m;
  int b[m];
  for(int i = 0; i < m; i++){
    cin >> b[i];
  }
  int max = 0;
  int maxn = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(int((b[j]*1.0)/(a[i]*1.0)) == (b[j]*1.0)/(a[i]*1.0)){
	if(b[j]/a[i] > max){
	  max = b[j]/a[i];
	  maxn = 1;
	} else if(b[j]/a[i] == max){
	  maxn++;
	}
      }
    }   
  }
  cout << maxn << endl;
  exit(0);
}