
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


int N;
vector<int> A;
vector<int> B;
vector<int> SA;
vector<int> SB;

void testcase(){
  cin >> N;
  A.resize(N); rep(i,N) cin >> A[i];
  B.resize(N); rep(i,N) cin >> B[i];
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  SA.assign(N+1,0);
  SB.assign(N+1,0);
  rep(i,N) SA[i+1] = SA[i] + A[N-1-i];
  rep(i,N) SB[i+1] = SB[i] + B[N-1-i];
  int l=N-1, r=1000000;
  while(r-l > 1){
    int m = (l+r) / 2;
    int xk = m - m/4;
    int Ascore = 100 * min(xk,m-N) + SA[xk-min(xk,m-N)];
    int Bscore = SB[min(N,xk)];
    if(Ascore >= Bscore) r = m; else l = m;
  }
  int ans = r - N;
  cout << ans << "\n";
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