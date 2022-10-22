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
    VI a(n);
    rep(i, n) cin >> a[i];
    if (a[n - 2] > a[n - 1]) {
      cout << -1 << '\n';
      continue;
    }
    if (a[n - 1] < 0) {
      bool ok = true;
      rep(i, n - 1) if (a[i] > a[i + 1]) ok = false;
      if (!ok) {
        cout << -1 << '\n';
      } else {
        cout << 0 << '\n';
      }
      continue;
    }
    cout << n - 2 << '\n';
    for(int i = n - 3; i >= 0; i--) {
      cout << i + 1 << ' ' << i + 2 << ' ' << n << '\n';
    }
  }
}