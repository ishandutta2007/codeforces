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
    ll a, b, c;
    cin >> a >> b >> c;
    bool ok = false;
    if (2 * b - c > 0 && (2 * b - c) % a == 0) {
      ok = true;
    }
    if (2 * b - a > 0 && (2 * b - a) % c == 0) {
      ok = true;
    }
    if ((a + c) % 2 == 0 && (a + c) / 2 % b == 0) {
      ok = true;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}