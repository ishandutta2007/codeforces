#include "bits/stdc++.h"
using namespace std;
#define REP(a,b) for(int a = 0;a < b;++a)
int main(){
  int n;
  cin >> n;
  vector<int> inputs;
  vector<int> geko;
  REP(i,2*n){
    int a;
    cin >> a;
    inputs.push_back(a);
    geko.push_back(i+1);
  }
  vector<int> gogo[2] = {inputs,inputs};
  REP(i,4*n+1){
    if(gogo[0] == geko or gogo[1] == geko){
      cout << i << endl;
      return 0;
    }
    REP(q,n){
      swap(gogo[0][2*q],gogo[0][2*q+1]);
      swap(gogo[1][q],gogo[1][q+n]);
    }
    swap(gogo[0],gogo[1]);
  }
  cout << -1 << endl;
}