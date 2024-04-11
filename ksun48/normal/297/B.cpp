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
int freqa[210000];
int freqb[210000];
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 0; i < 210000; i++){
    freqa[i] = 0;
    freqb[i] = 0;
  }
  set<int> fish;
  int a[n];
  int b[m];
  for(int i = 0; i < n; i++){
    cin >> a[i];
    fish.insert(a[i]);
  }
  for(int i = 0; i < m; i++){
    cin >> b[i];
    fish.insert(b[i]);
  }

  map<int,int> fishmap;
  int ii = 0;
  for(set<int>::iterator it = fish.begin(); it != fish.end(); it++){
    fishmap[*it] = ii;
    ii++;
  }
  for(int i = 0; i < n; i++){
    freqa[fishmap[a[i]]]++;
  }
  for(int i = 0; i < m; i++){
    freqb[fishmap[b[i]]]++;
  }
  int suma = 0;
  int sumb = 0;
  for(int i = 200100; i >= 0; i--){
    suma += freqa[i];
    sumb += freqb[i];
    if(suma > sumb){
      cout << "YES" << endl;
      exit(0);
      return 0 ;
    }
  }
  cout << "NO" << endl;
  exit(0);
}