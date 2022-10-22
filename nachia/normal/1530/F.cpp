
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

const int MOD = 31607;

int N;
vector<int> I;
vector<vector<int>> A;

int solve(){
  int ans = 0;
  vector<int> prod(N,1);
  rep(y,N) rep(x,N) prod[y] = prod[y] * A[y][x] % MOD;
  int T = 1;
  int p = 0;
  rep(i,1<<N){
    int x = 0;
    if(i){
      while(!(i&(1<<x))) x++;
      //cout << "x = " << x << endl;
      p ^= (1<<x);
      if(p & (1<<x)){
        rep(y,N) prod[y] = prod[y] * I[A[y][x]] % MOD;
        rep(y,N) T = T * A[y][x] % MOD;
      }
      else{
        rep(y,N) prod[y] = prod[y] * A[y][x] % MOD;
        rep(y,N) T = T * I[A[y][x]] % MOD;
      }
    }

    int tmp = T;
    rep(y,N) tmp = tmp * (1 + MOD - prod[y]) % MOD;
    if(i % 2 == 0) ans = ans + tmp;
    else ans = ans + MOD - tmp;
    if(ans >= MOD) ans -= MOD;
    //cout << "prod : ";
    //rep(y,N) cout << prod[y] << " "; cout << endl;
    //cout << "tmp = " << tmp << endl;
  }
  //cout << endl;
  return ans;
}

int main() {
  I.assign(MOD,1);
  for(int i=2; i<MOD; i++) I[i] = (MOD - MOD / i * I[MOD%i] % MOD) % MOD;
  cin >> N;
  vector<vector<int>> pA;
  pA.assign(N,vector<int>(N));
  rep(y,N) rep(x,N) cin >> pA[y][x];
  rep(y,N) rep(x,N) pA[y][x] = pA[y][x] * I[10000] % MOD;

  int ans = 0;
  rep(s,2){
    rep(t,2){
      A = pA;
      int T = 1;
      if(s == 1) rep(i,N){ T = T * A[i][i] % MOD; A[i][i] = 1; }
      if(t == 1) rep(i,N){ T = T * A[i][N-1-i] % MOD; A[i][N-1-i] = 1; }
      //rep(y,N){ rep(x,N) cout << A[y][x] << " "; cout << endl; } cout << endl;
      int tmp = solve();
      tmp = tmp * T % MOD;
      //cout << "tmp = " << tmp << endl;
      if(s == 1) tmp = MOD - tmp;
      if(t == 1) tmp = MOD - tmp;
      ans = (ans + tmp) % MOD;
    }
  }

  ans = (1 + MOD - ans) % MOD;
  cout << ans << "\n";
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;