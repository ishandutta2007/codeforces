#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  VI gc{0};
  rep(k, 5) {
    int sz = gc.size();
    rep(i, sz) gc.emplace_back(gc[sz - 1 - i] ^ (1 << k));
  }
  
  int p[32][32];
  auto f = [&](int i) {
    int x = gc[i];
    int res = 0;
    rep(k, 5) res |= (x >> k & 1) << (2 * k);
    return res;
  };
  rep(i, 32) rep(j, 32) {
    int pi = f(i), pj = f(j);
    p[i][j] = pi | (pj << 1);
  }
  // rep(i, 32) rep(j, 32) cout << p[i][j] << " \n"[j + 1 == 32];
  int n, k;
  cin >> n >> k;
  ll sm = 0;
  rep(i, n) rep(j, n - 1) {
    int d = p[i][j] ^ p[i][j+1];
    cout << d << " \n"[j + 2 == n];
    sm += d;
  }
  rep(i, n - 1) rep(j, n) {
    int d = p[i][j] ^ p[i+1][j];
    cout << d << " \n"[j + 1 == n];
    sm += d;
  }
  cout << flush;
  unordered_map<int, P> mp;
  rep(i, 32) rep(j, 32) {
    int x = p[i][j];
    assert(!mp.count(x));
    mp[x] = {i, j};
  }
  // cout << sm << endl;
  int x = p[0][0];
  rep(_, k) {
    int nx;
    cin >> nx;
    x ^= nx;
    auto [i, j] = mp[x];
    cout << i + 1 << ' ' << j + 1 << endl;
  }
}