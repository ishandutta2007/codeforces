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
    int n, m, k;
    cin >> n >> m >> k;
    int p = 0;
    int sz1 = n / m, sz2 = sz1 + 1;
    int cnt1 = m - n % m, cnt2 = m - cnt1;
    rep(_, k) {
      rep(_, cnt2) {
        cout << sz2;
        rep(_, sz2) {
          cout << ' ' << p + 1;
          p++;
          if (p == n) p = 0;
        }
        cout << '\n';
      }
      int q = p;
      rep(_, cnt1) {
        cout << sz1;
        rep(_, sz1) {
          cout << ' ' << q + 1;
          q++;
          if (q == n) q = 0;
        }
        cout << '\n';
      }
    }
    cout << '\n';
  }
}