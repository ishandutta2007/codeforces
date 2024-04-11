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
#include <vector>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  int s[n];
  int k[n];
  for(int i = 0; i < n; i++){
    cin >> s[i];
    k[i] = s[i];
  }
  sort(k, k+n);
  int id[n];
  for(int i = 0; i < n; i++){
    int s1 = -1;
    int e = n;
    while(1){
      int m = (s1+e)/2;
      if(k[m] < s[i]){
	s1 = m;
      } else if(k[m] > s[i]){
	e = m;
      } else if(k[m] == s[i]){
	id[i] = m;
	break;
      }
    }
  }
  cout << "YES" << endl;
  int num = int(2*n/3);
  int first = n-num;
  int a[n];
  int b[n];
  for(int i = 0; i < first; i++){
    a[i] = 0;
    b[i] = k[i];
  }
  if(num > 0){
    if(k[first] + 1 >= num){
      b[first] = k[first];
      a[first] = 0;
      for(int i = first+1; i < n; i++){
	b[i] = b[i-1] - 1;
	a[i] = k[i]-b[i];
      }
    } else {
      set<int> a1;
      set<int> b1;
      for(int i = first; i <= first+k[first]; i++){
	b[i] = k[first]-(i-first);
	a[i] = k[i] - b[i];
	a1.insert(a[i]);
	b1.insert(b[i]);
      }
      int nf = first+k[first] + 1;
      int mina = 0;
      for(int i = nf; i < n; i++){
	while(a1.count(mina) == 1 || b1.count(k[i]-mina) == 1){
	  mina++;
	}
	a[i] = mina;
	b[i] = k[i]-mina;
	a1.insert(a[i]);
	b1.insert(b[i]);
	mina++;

      }
    }
  }
  for(int i = 0; i < n; i++){
    cout << a[id[i]] << " ";
  }
  cout << endl;
  for(int i = 0; i < n; i++){
    cout << b[id[i]] << " ";
  }
  cout << endl;
}