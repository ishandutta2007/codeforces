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
    VI a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    int l = 0, r = n + 1;
    while(r - l > 1) {
      int c = (l + r) / 2;
      int cnt = 0;
      rep(i, n) {
        if (cnt <= b[i] && c - 1 - cnt <= a[i]) {
          cnt++;
        }
      }
      if (cnt >= c) l = c;
      else r = c;
    }
    cout << l << '\n';
  }
}