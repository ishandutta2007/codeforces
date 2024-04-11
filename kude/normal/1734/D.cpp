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
    int n, k;
    cin >> n >> k;
    k--;
    VI a(n);
    rep(i, n) cin >> a[i];
    bool ok = false;
    rep(_, 2) {
      ll mn = 0;
      ll now = 0;
      vector<pair<ll, ll>> bonus;
      for(int i = k + 1; i < n; i++) {
        now += a[i];
        if (now >= 0) {
          bonus.emplace_back(-mn, now);
          now = mn = 0;
        } else {
          chmin(mn, now);
        }
      }
      reverse(all(bonus));
      now = a[k];
      bool success = true;
      rrep(i, k) {
        while(bonus.size() && now >= bonus.back().first) {
          now += bonus.back().second;
          bonus.pop_back();
        }
        now += a[i];
        if (now < 0) {
          success = false;
          break;
        }
      }
      if (success) {
        ok = true;
        break;
      }
      reverse(all(a));
      k = n - 1 - k;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}