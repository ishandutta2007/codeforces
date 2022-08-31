#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#include <complex>
#include <deque>
#include <map>
#include <utility>
#include <limits>
// numeric_limits<int>::max()
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

int compare_dec (const void * a, const void * b) {
  if ( *(int*)a < *(int*)b ) return 1;
  if ( *(int*)a > *(int*)b ) return -1;
  return 0;
}

int compare_inc (const void * a, const void * b) {
  if ( *(int*)a > *(int*)b ) return 1;
  if ( *(int*)a < *(int*)b ) return -1;
  return 0;
}

main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int m;
  cin >> m;
  int dis[m];
  for(int i = 0; i < m; i++){
    cin >> dis[i];
  }
  qsort(dis, m, sizeof(int), compare_inc);
  int n;
  cin >> n;
  int item[n];
  for(int i = 0; i < n; i++){
    cin >> item[i];
  }
  qsort(item, n, sizeof(int), compare_dec);
  int curd = 0;
  int price = 0;
  int curitem = 0;
  while(curitem < n){
    if(curd < m && curitem+dis[curd] <= n){
      for(int i = 0; i < dis[curd]; i++){
	price += item[curitem];
	curitem++;
      }
      if(curitem < n){
	curitem++;
      } 
      if(curitem < n){
	curitem++;
      } 
    } else {
      price += item[curitem++];      
    }
  }
  cout << price << endl;
}