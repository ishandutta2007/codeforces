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

int oldest[5000010];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    VI a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    n = a.size();

    memset(oldest, -1, (m + 1) * sizeof(int));
    vector<char> exists(m + 1);
    for(int x: a) exists[x] = true;
    int oks = a[0] == 1;
    int l = 1, r = 2;
    auto add = [&](int v) {
      oks += exists[v] && oldest[v] < l;
      oldest[v] = v;
      for (int i = 2, j = 2 * v; j <= m; i++, j += v) {
        if (oldest[i] < l) continue;
        if (oldest[j] < oldest[i]) {
          oks += exists[j] && oldest[j] < l;
          oldest[j] = oldest[i];
        }
      }
    };
    if (a[0] == 1) {
      while(oks < n) add(r++);
      int ans = r - 1 - 1;
      cout << ans << '\n';
      continue;
    }
    int mn = a[0];
    int ans = m;
    for(l = 2; l <= mn; l++) {
      while(r <= m && oks < n) add(r++);
      if (oks != n) break;
      chmin(ans, r - l - 1);
      for (int i = l; i <= m; i += l) oks -= exists[i] && oldest[i] == l;
    }
    cout << ans << '\n';
  }
}