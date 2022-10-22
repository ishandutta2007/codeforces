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
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    int l = 0, r = n + 1;
    while(r - l > 1) {
      int c = (l + r) / 2;
      auto b = a;
      bool ok = true;
      for(int i = c; i >= 1; i--) {
        b.erase(remove_if(all(b), [&](int x) { return x > i; }), b.end());
        if (b.empty()) {
          ok = false;
          break;
        }
        b.erase(max_element(all(b)));
        if (!b.empty()) {
          *min_element(all(b)) += i;
        }
      }
      (ok ? l : r) = c;
    }
    cout << l << '\n';
  }
}