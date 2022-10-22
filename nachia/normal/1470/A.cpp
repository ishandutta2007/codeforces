
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N,M;
vector<int> K;
vector<int> C;

void testcase(){
  cin >> N >> M;
  K.resize(N);
  rep(i,N){ cin >> K[i]; K[i]--; }
  C.resize(M);
  rep(i,M) cin >> C[i];
  sort(K.begin(),K.end());
  reverse(K.begin(),K.end());

  vector<int> I(N,0);
  for(int i=1; i<N; i++) I[i] = min(I[i-1]+1,K[i]);

  ll ans = 0;
  rep(i,N) ans += C[I[i]];
  cout << ans << "\n";
}

int main(){
  int T; cin >> T; while(T--)
  testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;