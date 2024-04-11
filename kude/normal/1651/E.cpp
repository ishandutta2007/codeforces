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
  int n;
  cin >> n;
  vector<array<int, 2>> g(2 * n);
  rep(i, 2 * n) rep(j, 2) g[i][j] = -1;
  rep(i, 2 * n) {
    auto add = [&](int i, int j) {
      if (g[i][0] == -1) g[i][0] = j;
      else g[i][1] = j;
    };
    int x, y;
    cin >> x >> y;
    x--, y--;
    add(x, y);
    add(y, x);
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++) ans += ll(n + 1 - i) * i * ((n + 1) * n / 2);
  // cout << ans << endl;
  vector<char> visited(2 * n);
  VI to(2 * n);
  VI vs;
  rep(i, n) if (!visited[i]) {
    vs.clear();
    int v = i;
    int p = -1;
    do {
      vs.emplace_back(v);
      visited[v] = true;
      if (p != g[v][0]) {
        to[v] = g[v][0];
      } else {
        to[v] = g[v][1];
      }
      p = v;
      v = to[v];
    } while(v != i);
    
    int sz = vs.size();
    rep(i, sz) vs.emplace_back(vs[i]);
    vs.insert(vs.begin(), vs.back());
    auto f = [&](int l, int r, int x, int y) {
      if (r == -1) {
        if (x > y) swap(x, y);
        int res = 0;
        for(int p: {y - x - 1, x - n, 2 * n - (y + 1)}) {
          res += (p + 1) * p / 2;
        }
        return res;
      }
      int mn = n, mx = 2 * n - 1;
      rep(_, 2) {
        if (l <= x && x <= r) return 0;
        else if (x < l) {
          chmax(mn, x + 1);
        } else {
          assert(r < x);
          chmin(mx, x - 1);
        }
        swap(x, y);
      }
      assert(mn <= l && l <= r && r <= mx);
      return (l - mn + 1) * (mx - r + 1);
    };
    for(int i = 1; i < sz; i += 2) {
      int ly = 1001001001, ry = -1;
      int lx = 1001001001, rx = -1;
      for(int j = i; j < i + sz; j += 2) {
        chmin(lx, vs[j]);
        chmax(rx, vs[j]);
        assert(0 <= lx && lx <= rx && rx <= n - 1);
        ans -= ll(lx + 1) * (n - rx) * f(ly, ry, vs[i - 1], vs[j + 1]);
        chmin(ly, vs[j + 1]);
        chmax(ry, vs[j + 1]);
      }
    }
  }
  cout << ans << '\n';
}