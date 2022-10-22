#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


bool solve(int N, int M, vector<int> A, int k){
  rep(i,N) A[i] = (A[i] + k) % N;
  rep(i,N) while(A[i] != i){ swap(A[A[i]],A[i]); M--; }
  return M >= 0;
}


void testcase(){
  int N,M; cin >> N >> M;
  vector<int> A(N);
  rep(i,N){ cin >> A[i]; A[i]--; }
  vector<int> CCorrectPoint(N,0);
  rep(i,N) CCorrectPoint[(N-A[i]+i)%N]++;
  vector<int> CanK;
  rep(i,N) if(CCorrectPoint[i] + 2*M >= N) CanK.push_back(i);
  vector<int> ans;
  for(auto k : CanK) if(solve(N,M,A,k)) ans.push_back(k);
  cout << ans.size();
  for(auto a : ans) cout << " " << a;
  cout << "\n";
}


int main(){
  int T; cin >> T;
  while(T--) testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;