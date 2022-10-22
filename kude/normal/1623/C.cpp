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
    VL h(n);
    rep(i, n) cin >> h[i];
    int l = 0, r = 1001001001;
    VL a;
    while(r - l > 1) {
      int c = (l + r) / 2;
      a = h;
      for(int i = n - 1; i >= 2; i--) {
        if (a[i] < c) {
          break;
        }
        ll d = min<ll>((a[i] - c) / 3, h[i] / 3);
        a[i] -= 3 * d;
        a[i - 1] += d;
        a[i - 2] += 2 * d;
      }
      if (*min_element(all(a)) >= c) {
        l = c;
      } else {
        r = c;
      }
    }
    cout << l << '\n';
  }
}