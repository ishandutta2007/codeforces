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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    bool flip = a < b;
    if (flip) {
      swap(a, b);
    }
    VI ans(n);
    if (a == b && 2 * a + 2 <=n) {
      int p = 1, q = a + 2;
      rep(i, 2 * a + 2) {
        if (i % 2 == 0) {
          cout << p;
          p++;
        } else {
          cout << q;
          q++;
        }
        cout << " \n"[i + 1 == n];
      }
      for (int i = 2 * a + 2; i < n; i++) {
        cout << q++ << " \n"[i + 1 == n];
      }
    } else if (a == b + 1 && 2 * a + 1 <= n) {
      int p = n + 1 - a, q = p - 1;
      VI ans(n);
      rep(i, 2 * a + 1) {
        if (i % 2 == 0) ans[i] = q--;
        else ans[i] = p++;
      }
      for(int i = 2 * a + 1; i < n; i++) ans[i] = q--;
      if (flip) {
        for(int& x: ans) x = n + 1 - x;
      }
      rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    } else {
      cout << -1 << '\n';
      continue;
    }
  }
}