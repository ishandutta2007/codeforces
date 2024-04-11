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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    bool d[8][8]{};
    rep(_, m) {
      int x, y;
      cin >> x >> y;
      d[x-1][y-1] = true;
    }
    auto check = [&] {
      bool r[8]{}, c[8]{};
      rep(i, n) rep(j, n) if (d[i][j]) {
        if (r[i]) return false;
        if (c[j]) return false;
        r[i] = c[j] = true;
      }
      return true;
    };
    bool ok = false;
    rep(i, n) rep(j, n) if (!ok && d[i][j]) {
      d[i][j] = false;
      rep(ni, n) rep(nj, n) if ((i != ni || j != nj) && !d[ni][nj]) {
        d[ni][nj] = true;
        ok |= check();
        d[ni][nj] = false;
      }
      d[i][j] = true;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}