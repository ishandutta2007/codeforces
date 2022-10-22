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
    int n, q;
    cin >> n >> q;
    VI a(n);
    rep(i, n) cin >> a[i];
    vector<char> take(n);
    int l = 0, r = n + 1;
    auto f = [&](int c) {
      take.assign(n, false);
      int rest = c;
      rep(i, n) if (a[i] <= q) take[i] = true, rest--;
      if (rest <= 0) return;
      rrep(i, n) if (!take[i]) {
        take[i] = true;
        if (--rest == 0) break;
      }
    };
    while(r - l > 1) {
      int c = (l + r) / 2;
      f(c);
      int qc = q;
      rep(i, n) if (take[i]) {
        qc -= a[i] > qc;
      }
      (qc >= 0 ? l : r) = c;
    }
    f(l);
    string ans(n, '0');
    rep(i, n) if (take[i]) ans[i] = '1';
    cout << ans << '\n';
  }
}