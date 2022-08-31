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
int p[1001001];
int q[1001001];
int freq[1001001];
//int negfreq[1001001];
int cumsum[1001001];
int numpos[1001001];
map<int, int> map1;
map<int, int> map2;

main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  int size = 1;
  for(int i = 0; i < 1001001; i++){
    freq[i] = 0;
    q[i] = 0;
    cumsum[i] = 0;
    numpos[i] = 0;
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &p[i]);
    if(map1.count(p[i]) == 0){
      map1[p[i]] = size;
      map2[size] = p[i];
      p[i] = map1[p[i]];
      size++;
    } else {
      p[i] = map1[p[i]];
    }
    freq[p[i]]++;
  }
  for(int i = 1; i < size; i++){
    if(freq[i] % 2 == 1){
      cout << "NO" << endl;
      exit(0);
    }
  }
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int k;
    cin >> k;
    k--;
    q[k] = -1;
    //cout << q[k] << endl;
  }
  /*for(int i = 0; i < n; i++){
    if(q[i] == -1){
      cumsum[p[i]]--;
      if(cumsum[p[i]] < 0){
	cout << "NO" << endl;
	exit(0);
      }
    } else {
      if(numpos[p[i]] < freq[p[i]]/2){
	q[i] = 1;
	numpos[p[i]]++;
	cumsum[p[i]]++;
      } else {
	q[i] = -1;
	cumsum[p[i]]--;
	if(cumsum[p[i]] < 0){
	  cout << "NO" << endl;
	  exit(0);
	}
      }
    }
    }*/
  deque<int> num;
  for(int i = n-1; i >= 0; i--){
    if(q[i] == -1){
      num.push_front(-p[i]);
    } else {  
      if((num.front()) == -p[i]){
	q[i] = 1;
	num.pop_front();
      } else {
	q[i] = -1;
	num.push_front(-p[i]);
      }
    }
  }
  if(!num.empty()){
    cout << "NO" << endl;
    exit(0);
  }
  cout << "YES" << endl;
  for(int i = 0; i < n; i++){
    printf("%d ", q[i]*map2[p[i]]);
    //cout << q[i]*map2[p[i]] << " ";
  }
  cout << endl;
}