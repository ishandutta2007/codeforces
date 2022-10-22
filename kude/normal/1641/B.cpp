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
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    if (n % 2) {
      cout << -1 << '\n';
      continue;
    }
    auto a_sorted = a;
    sort(all(a_sorted));
    bool ok = true;
    for(int i = 0; i < n; i += 2) {
      if (a_sorted[i] != a_sorted[i + 1]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    vector<P> ans;
    VI t;
    int sz = n;
    while(sz != 0) {
      if (a[sz - 1] == a[sz - 2]) {
        t.emplace_back(2);
        sz -= 2;
        continue;
      }
      int i = sz - 2;
      while(a[i] != a[sz - 1]) i--;
      for(int j = sz - 1; j > i; j--) {
        ans.emplace_back(i+sz-j, a[j]);
      }
      t.emplace_back(2 * (sz - (i + 1)));
      reverse(a.begin() + i + 1, a.begin() + sz);
    }
    cout << ans.size() << '\n';
    for(auto [i, j]: ans) cout << i << ' ' << j << '\n';
    reverse(all(t));
    int tsz = t.size();
    cout << tsz << '\n';
    rep(i, tsz) cout << t[i] << " \n"[i + 1 == tsz];
  }
}