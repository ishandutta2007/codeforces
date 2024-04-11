#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  // cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    VVI a(n, VI(m));
    rep(i, n) rep(j, m) cin >> a[i][j];
    vector<tuple<int, int, int>> todo;
    vector<vector<char>> added(n, vector<char>(m));
    rep(i, n - 1) rep(j, m - 1) {
      int x = a[i][j];
      bool ok = true;
      rep(di, 2) rep(dj, 2) {
        if (a[i + di][j + dj] != x) {
          ok = false;
          break;
        }
      }
      if (ok) {
        todo.emplace_back(i, j, x);
        added[i][j] = true;
      }
    }
    vector<tuple<int, int, int>> ans;
    auto idxchk = [&](int i, int j) { return 0 <= i && i < n && 0 <= j && j < m; };
    while(!todo.empty()) {
      auto [i, j, x] = todo.back(); todo.pop_back();
      ans.emplace_back(i, j, x);
      rep(di, 2) rep(dj, 2) {
        int ni = i + di;
        int nj = j + dj;
        if (!idxchk(ni, nj)) continue;
        a[ni][nj] = -1;
      }
      for(int x = i - 1; x <= i + 1; x++) {
        for(int y = j - 1; y <= j + 1; y++) {
          if (!idxchk(x, y) || !idxchk(x + 1, y + 1) || added[x][y]) continue;
          int col = -1;
          rep(dx, 2) rep(dy, 2) {
            int nx = x + dx, ny = y + dy;
            if (a[nx][ny] == -1) continue;
            if (col == -1) col = a[nx][ny];
            else if (col != a[nx][ny]) col = -2;
          }
          if (col >= 0) {
            todo.emplace_back(x, y, col);
            added[x][y] = true;
          }
        }
      }
    }
    bool all_done = true;
    rep(i, n) rep(j, m) if (a[i][j] != -1) all_done = false;
    if (!all_done) {
      cout << -1 << '\n';
    } else {
      reverse(all(ans));
      int sz = ans.size();
      cout << sz << '\n';
      for(auto [i, j, x]: ans) cout << i + 1 << ' ' << j + 1 << ' ' << x << '\n';
    }
  }
}