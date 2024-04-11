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
int main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("input.txt", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("output.txt", "w", stdout);

  int n; 
  scanf("%d", &n);
  int lines[n];
  for(int i=0; i<n; i++) {
    scanf("%d", &lines[i]);
  }
  int r1, c1, r2, c2;
  scanf("%d%d%d%d", &r1, &c1, &r2, &c2); // from (r1,c1) to (r2,c2)
  r1--; c1--; r2--; c2--;  

  int nlines[n];
  if(r1 <= r2){
    for(int i = 0; i < n; i++){
      nlines[i] = lines[i];
    }
  } else {
    for(int i = 0; i < n; i++){
      nlines[i] = lines[n-1-i];
    }
    int a;
    r1 = n-1-r1;
    r2 = n-1-r2;
    
  }
  //cout << r1 << " " << r2 << endl;
  //cout << c1 << " " << c2 << endl;
  int min1 = c1;
  for(int i = r1+1; i <= r2; i++){
    min1 = Min(min1, nlines[i]);
    //cout << nlines[i] << endl;
  }
  //cout << "min1 " << min1 << endl;
  int ans = r2-r1+Abs(min1-c2);
  //cout << ans << endl;
  int upmin = min1;
  for(int i = r1; i >= 0; i--){
    if(nlines[i] < upmin){
      upmin = nlines[i];
      //cout << "a " << upmin << endl;
      ans = Min(ans, r1-i+r2-i+Abs(upmin-c2));
    }
  }
  int downmin = min1;
  for(int i = r2; i < n; i++){
    if(nlines[i] < downmin){
      downmin = nlines[i];
      ans = Min(ans, i-r1+i-r2+Abs(downmin-c2));
    } 
  }
  //cout << ans << endl;
  printf("%d\n", ans);
  return 0;
}