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
    ll hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    bool ok = false;
    for (int x = 0, y = k; x <= k; x++, y--) {
      ll nhc = hc + x * a;
      ll ndc = dc + y * w;
      ll cc = (nhc + dm - 1) / dm;
      ll cm = (hm + ndc - 1) / ndc;
      if (cm <= cc) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}