
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int n,k;

int ask(int p){
  p %= n;
  if(p < 0) p += n;
  cout << "? " << (p+1) << "\n" << flush;
  int res; cin >> res;
  return res;
}

void testcase(){
  cin >> n >> k;
  int l,r;
  int turnid = 0;
  for(int p=0; ; ){
    int res = ask(p);
    if(res > k){
      l = p - turnid;
      r = p;
      turnid++;
      break;
    }
    if(res < k){
      l = p + 1;
      r = p + turnid + 1;
      turnid++;
      break;
    }
    p += turnid;
    turnid++;
  }

  while(r-l > 1){
    int m = (l+r) / 2;
    int res = ask(m);
    if(res == k){ l=m; r=m+1; }
    if(res < k){ l=m+1; }
    if(res > k){ r=m; }
  }

  l %= n;
  if(l < 0) l += n;
  cout << "! " << (l+1) << "\n" << flush;
}

int main(){
  // int T; cin >> T; while(T--)
  testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;