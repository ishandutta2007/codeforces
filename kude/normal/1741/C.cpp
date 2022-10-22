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

template<class T>
vector<T> divisors(T x) {
  vector<T> res1, res2;
  T d = 1;
  for(; d * d < x; d++) {
    if (x % d == 0) {
      res1.emplace_back(d);
      res2.emplace_back(x / d);
    }
  }
  if (d * d == x) res1.emplace_back(d);
  res1.insert(res1.end(), res2.rbegin(), res2.rend());
  return res1;
}

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
    int ans = n;
    for(ll d: divisors(accumulate(all(a), 0LL))) {
      bool ok = true;
      int mx = 0;
      for(int i = 0; i < n;) {
        ll s = 0;
        int j = i;
        while(j < n && s < d) s += a[j++];
        if (s != d) {
          ok = false;
          break;
        }
        chmax(mx, j - i);
        i = j;
      }
      if (ok) chmin(ans, mx);
    }
    cout << ans << '\n';
  }
}