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
    VVI a(n, VI(m));
    rep(i, n) rep(j, m) cin >> a[i][j];
    int ans_i = -1, ans_j = -1;
    VI tmp;
    [&]{
      rep(i, n) {
        tmp = a[i];
        sort(all(tmp));
        if (tmp != a[i]) {
          int j1 = 0, j2 = m - 1;
          while(tmp[j1] == a[i][j1]) j1++;
          while(tmp[j2] == a[i][j2]) j2--;
          rep(i, n) swap(a[i][j1], a[i][j2]);
          ans_i = j1, ans_j = j2;
          return;
        }
      }
    }();
    if (ans_i == -1) ans_i = ans_j = 0;
    bool ok = true;
    rep(i, n) rep(j, m - 1) if (a[i][j] > a[i][j+1]) ok = false;
    if (ok) {
      cout << ans_i + 1 << ' ' << ans_j + 1 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}