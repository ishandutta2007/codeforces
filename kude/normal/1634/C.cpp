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
    int n, m;
    cin >> n >> m;
    int tot = n * m;
    int evens = tot / 2, odds = tot - evens;
    if (evens % m || odds % m) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    rep(b, 2) {
      for (int i = b + 1; i <= tot;) {
        rep(_, m) {
          cout << i << " \n"[_ + 1 == m];
          i += 2;
        }
      }
    }
  }
}