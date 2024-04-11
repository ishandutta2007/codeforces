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
    int n, k, b;
    ll s;
    cin >> n >> k >> b >> s;
    if ((ll)k * b > s) {
      cout << -1 << '\n';
      continue;
    }
    ll rest = s - (ll)b * k;
    VL a(n);
    a[0] = (ll)b * k;
    rep(i, n) {
      ll v = min<ll>(k - 1, rest);
      a[i] += v;
      rest -= v;
    }
    if (rest) {
      cout << -1 << '\n';
    } else {
      rep(i, n) cout << a[i] << " \n"[i + 1 == n];
    }
  }
}