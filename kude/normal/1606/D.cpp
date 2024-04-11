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

void solve() {
  int n, m;
  cin >> n >> m;
  VVI a(n, VI(m));
  rep(i, n) rep(j, m) cin >> a[i][j];
  constexpr int INF = 1001001001;
  VVI min_acc_l(n, VI(m + 1, INF)), min_acc_r = min_acc_l;
  VVI max_acc_l(n, VI(m + 1, -INF)), max_acc_r = max_acc_l;
  rep(i, n) {
    rep(j, m) {
      min_acc_l[i][j + 1] = min(min_acc_l[i][j], a[i][j]);
      max_acc_l[i][j + 1] = max(max_acc_l[i][j], a[i][j]);
    }
    rrep(j, m) {
      min_acc_r[i][j] = min(min_acc_r[i][j + 1], a[i][j]);
      max_acc_r[i][j] = max(max_acc_r[i][j + 1], a[i][j]);
    }
  }
  VI ord(n);
  iota(all(ord), 0);
  for(int j = 1; j < m; j++) {
    sort(all(ord), [&](int i1, int i2) { return min_acc_l[i1][j] > min_acc_l[i2][j]; });
    multiset<int> small_l, large_r;
    int small_r = -INF;
    rep(i, n) small_l.insert(max_acc_l[i][j]), large_r.insert(min_acc_r[i][j]);
    rep(idx, n - 1) {
      int i = ord[idx];
      small_l.erase(small_l.find(max_acc_l[i][j]));
      large_r.erase(large_r.find(min_acc_r[i][j]));
      chmax(small_r, max_acc_r[i][j]);
      if (*small_l.rbegin() < min_acc_l[i][j] && small_r < *large_r.begin()) {
        cout << "YES\n";
        string ans(n, 'B');
        rep(ii, idx + 1) {
          int i = ord[ii];
          ans[i] = 'R';
        }
        cout << ans << ' ' << j << '\n';
        return;
      }
    }
  }
  cout << "NO\n";
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    solve();
  }
}