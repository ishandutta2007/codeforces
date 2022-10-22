
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


int N;
vector<int> A;

void testcase(){
  cin >> N;
  int ans = 0;
  A.resize(N); rep(i,N){ cin >> A[i]; A[i]--; }
  vector<int> cntA(N,0);
  rep(i,N) cntA[A[i]]++;
  vector<int> notfoundAs;
  rep(i,N) if(cntA[i] == 0) notfoundAs.push_back(i);
  ans = N - notfoundAs.size();
  int p = 0;
  while(notfoundAs.size() > 1){
    while(cntA[A[p]] <= 1) p++;
    if(notfoundAs[0] == p) swap(notfoundAs[0],notfoundAs[1]);
    cntA[A[p]]--;
    A[p] = notfoundAs[0];
    cntA[A[p]]++;
    swap(notfoundAs[0],notfoundAs.back()); notfoundAs.pop_back();
  }
  if(notfoundAs.size() > 0){
    vector<int> doubledA;
    rep(i,N) if(cntA[A[i]] >= 2) doubledA.push_back(i);
    if(doubledA[0] == notfoundAs[0]) swap(doubledA[0],doubledA[1]);
    cntA[A[doubledA[0]]]--;
    A[doubledA[0]] = notfoundAs[0];
    cntA[A[doubledA[0]]]++;
    notfoundAs.pop_back();
  }
  cout << ans << "\n";
  rep(i,N){ if(i) cout << " "; cout << (A[i]+1); } cout << "\n";
}

int main() {
  int T; cin >> T;
  while(T--) testcase();
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;