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
    ll k, x;
    cin >> k >> x;
    if (k == 1) {
      cout << 1 << '\n';
      continue;
    }
    ll l = 0, r = k;
    auto f1 = [&](ll c, ll x) {
      return c * (c + 1) / 2 < x;
    };
    while(r - l > 1) {
      ll c = (r + l) / 2;
      if (f1(c, x)) l = c;
      else r = c;
    }
    if (r < k) {
      cout << r << '\n';
      continue;
    }
    x -= k * (k + 1) / 2;
    if (x <= 0) {
      cout << r << '\n';
      continue;
    }
    auto f2 = [&](ll c, ll x) {
      ll cnt = k - 1 - c + 1;
      return cnt * (c + k - 1) / 2 < x;
    };
    r = k, l = 1;
    while(r - l > 1) {
      ll c = (l + r) / 2;
      if (f2(c, x)) r = c;
      else l = c;
    }
    cout << k + (k - l) << '\n';
  }
}