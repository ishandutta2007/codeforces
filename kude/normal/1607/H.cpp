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
    VI a(n), b(n), m(n);
    rep(i, n) cin >> a[i] >> b[i] >> m[i];
    map<int, VI> mp;
    VI ans1(n); //, ans2(n);
    rep(i, n) mp[a[i] + b[i] - m[i]].push_back(i);
    int tot = 0;
    for(auto& [k, is]: mp) {
      vector<tuple<int, int, int>> segs;
      for(int i: is) {
        int mn = max(a[i] - m[i], 0);
        int mx = min(a[i], a[i] + b[i] - m[i]);
        segs.emplace_back(mn, mx, i);
      }
      sort(all(segs), [&](const auto& x, const auto& y) {
        return get<1>(x) < get<1>(y);
      });
      int last = -1001001001;
      for(auto [mn, mx, i]: segs) {
        if (last < mn) {
          last = mx;
          tot++;
          ans1[i] = last;
        } else {
          ans1[i] = last;
        }
      }
    }
    cout << tot << '\n';
    rep(i, n) {
      int ai = ans1[i];
      int bi = a[i] + b[i] - m[i] - ai;
      cout << a[i] - ai << ' ' << b[i] - bi << '\n';
    }
  }
}