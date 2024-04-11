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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll g = gcd(a, b);
    a /= g, b /= g;
    g = gcd(c, d);
    c /= g, d /= g;
    if (a == c && b == d) {
      cout << 0 << '\n';
    } else if (!a || !c) {
      cout << 1 << '\n';
    } else if (a * d % (b * c) == 0 || b * c % (a * d) == 0) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
}