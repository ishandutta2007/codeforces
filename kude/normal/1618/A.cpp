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
    VI b(7);
    rep(i, 7) cin >> b[i];
    [&]{
      rep(i, 7) rep(j, i) rep(k, j) {
        int a1 = b[i], a2 = b[j], a3 = b[k];
        if ((ll)a1 + a2 + a3 != b.back()) continue;
        bool ok = true;
        for(int x: {a1 + a2, a2 + a3, a3 + a1}) {
          bool found = false;
          rep(i, 7) if (b[i] == x) {
            found = true;
            break;
          }
          if (!found) {
            ok = false;
            break;
          }
        }
        if (ok) {
          cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
          return;
        }
      }
    }();
  }
}