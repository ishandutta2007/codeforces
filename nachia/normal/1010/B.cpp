#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int M,N;
int P[30] = {};

bool ask_if_greater_than_y(int y){
  cout << y << "\n" << flush;
  int res; cin >> res;
  if(res == -2) exit(0);
  if(res == 0) exit(0);
  return res == 1;
}

int main(){
  cin >> M >> N;
  rep(i,N){
    if(!ask_if_greater_than_y(1)) P[i] = 0;
    else P[i] = 1;
  }

  int l=1, r=M+1;
  int t=0;
  while(r-l > 1){
    int m = (l+r)/2;
    bool gtm = ask_if_greater_than_y(m);
    if(P[t%N] == 0) gtm = !gtm;
    if(gtm) l=m; else r=m;
    t++;
  }
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;