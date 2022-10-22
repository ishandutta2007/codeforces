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
  int n;
  cin >> n;
  VL a(n + 1), b(n + 1);
  rep(i, n) cin >> a[i + 1];
  rep(i, n) cin >> b[i + 1];
  for(int i = 2; i <= n; i++) {
    b[i] = b[i] - a[i];
    a[i] = 0;
  }
  b[1] = -a[1];
  a[1] = 1;
  struct S {
    ll a = 0, b = 0;
    S operator+(const S& rhs) const {
      return {a + rhs.a, b + rhs.b};
    }
  };
  vector<S> d;
  for(int i = 2; i <= n; i++) {
    ll p = a[i] - a[1];
    ll q = b[i] - b[1];
    d.push_back({p, q});
    for(int j = i; j <= n; j += i) {
      a[j] -= p;
      b[j] -= q;
    }
  }
  d.push_back({a[1], b[1]});
  ll cnst = 0;
  int sz = d.size();
  rep(i, sz) {
    if (d[i].a == 0) {
      cnst += abs(d[i].b);
      swap(d[i], d.back());
      d.pop_back();
      sz--;
      i--;
    } else if (d[i].a < 0) {
      d[i].a *= -1;
      d[i].b *= -1;
    }
  }
  sort(all(d), [&](const S& l1, const S& l2) {
    auto [a1, b1] = l1;
    auto [a2, b2] = l2;
    return  __int128(-b1) * a2 < __int128(-b2) * a1;
  });

  // for(auto [a, b]: d) cout << a << ' ' << b << '\n';

  vector<S> acc_l(sz + 1), acc_r(sz + 1);
  rep(i, sz) acc_l[i + 1] = acc_l[i] + d[i];
  rrep(i, sz) acc_r[i] = acc_r[i + 1] + d[i];

  int q;
  cin >> q;
  while(q--) {
    ll x;
    cin >> x;
    int l = -1, r = sz;
    while(r - l > 1) {
      int c = (l + r) / 2;
      auto [a, b] = d[c];
      if (a * x + b >= 0) l = c;
      else r = c;
    }
    auto [al, bl] = acc_l[l + 1];
    auto [ar, br] = acc_r[l + 1];
    ll ans = (al * x + bl) - (ar * x + br) + cnst;
    // cout << al << ' ' << bl << ' ' << ar << ' ' << br << ' ';
    cout << ans << '\n';
  }
}