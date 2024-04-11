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
    ll a, b, x;
    cin >> a >> b >> x;
    if (a > b) swap(a, b);
    bool ok = false;
    while(x <= b) {
      // 0 < a < b
      if ((b - x) % a == 0) {
        ok = true;
        break;
      }
      b = b % a + a;
      if (b == a) break;
      a = b - a;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}