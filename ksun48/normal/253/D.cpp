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

int DEBUG = 0;
int main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("input.txt", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("output.txt", "w", stdout);
  int n, m, k;
  cin >> n >> m >> k;
  char stuff[n+1][m+1];
  for(int i = 0; i < n; i++){
    cin >> stuff[i+1];
  }
  for(int i = 0; i < m; i++){
    stuff[0][i] = '#';
  }
  int csum[n+1][m];
  for(int i = 0; i < m; i++){
    int sum = 0;
    for(int j = 0; j <= n; j++){
      if(stuff[j][i] == 'a'){
	sum++;
      }
      csum[j][i]=sum;
    }
  }
  /*for(int i = 0; i <= n; i++){
    for(int j = 0; j < m; j++){
    cout << csum[i][j] << " ";
    }
    cout << endl;
    }*/
  LL a = 0;
  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      LL b = 0;
      vector<int> vec[26];
      for(int c = 0; c < m; c++){
	if(stuff[i][c] == stuff[j][c]){
	  vec[stuff[i][c]-'a'].push_back(c);
	  //cout << c << " " << stuff[i][c] << endl;
	}
      }
      if(DEBUG) cout << "i " << i << " j " << j << endl;
      for(int c = 0; c < 26; c++){
	if(vec[c].size() > 1){
	  if(DEBUG)cout << "char " << c << endl;
	  if(DEBUG) cout << "size " << c << " " << vec[c].size() << endl;
	  LL d = 0;
	  int sum = csum[j][vec[c][0]] - csum[i-1][vec[c][0]];
	  int p1 = 0;
	  if(DEBUG) cout << "p1 " << p1 << " p2 " << 0 << " sum " << sum << endl;
	  for(int p2 = 1; p2 < vec[c].size(); p2++){
	    for(int kk = vec[c][p2-1]+1; kk <= vec[c][p2]; kk++){
	      sum += csum[j][kk]-csum[i-1][kk];
	    }
	    if(DEBUG) cout << "p1 " << p1 << " p2 " << p2 << " sum " << sum << endl;
	    while(sum > k){
	      if(DEBUG) {
		//printf("sum= %d, k= %d, vec[%d][%d]= %d\n", sum, k, c, p1+1, vec[c][p1+1]);
	      }
	      if(DEBUG) cout << "p1+1 " << p1+1 << " size " << vec[c].size() << endl;
	      for(int kk = vec[c][p1]; kk < vec[c][p1+1]; kk++){
		sum += csum[i-1][kk] - csum[j][kk];
	      }
	      p1++;
	      if(DEBUG) cout << "p1 " << p1 << " p2 " << p2 << " sum " << sum << endl;
	      //cout << sum << " BADsum" << endl;
	      if(p1 >= p2){
		break;
	      }
	    }
	    //cout << "p1 " << p1 << " p2 " << p2 << endl;
	    d += (LL)(p2 - p1);
	  }
	  b += d;
	  if(d > 0){
	    //cout << c << " " << d << endl;
	  }
	}
      }
      //cout << "NUM " << b << endl;
      a += b;
    }
  }
  cout << a << endl;
  return 0;
}