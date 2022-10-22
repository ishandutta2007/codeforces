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
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    if (b < a) {
      if (!(b + 1 == a && a == n / 2)) {
        cout << -1 << '\n';
      } else {
        rrep(i, n) cout << i + 1 << " \n"[i == 0];
      }
      continue;
    }
    if (n - a - 1 < n / 2 || b + 1 - 1 < n / 2) {
      cout << -1 << '\n';
      continue;
    }
    VI p(n);
    iota(all(p), 0);
    swap(p[a], p[b]);
    rrep(i, n) cout << p[i] + 1 << " \n"[i == 0];
  }
}