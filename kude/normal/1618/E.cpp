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
    VL b(n);
    rep(i, n) cin >> b[i];
    reverse(all(b));
    if (n == 1) {
      cout << "YES\n";
      cout << b[0] << '\n';
      continue;
    } else if (n == 2) {
      ll a[2];
      a[0] = -b[0] + 2 * b[1];
      a[1] = 2 * b[0] - b[1];
      if (a[0] <= 0 || a[1] <= 0 || a[0] % 3 || a[1] % 3) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        cout << a[1] / 3 << ' ' << a[0] / 3 << '\n';
      }
      continue;
    }
    ll sum = accumulate(all(b), 0LL);
    ll sn = n * (n + 1) / 2;
    VL a(n, sum);
    rep(i, n) {
      a[i] += sn * (-b[i] + b[(i + 1) % n]);
    }
    bool ok = true;
    ll nsn = n * sn;
    rep(i, n) {
      if (a[i] % nsn) {
        ok = false;
        break;
      }
      a[i] /= nsn;
      if (a[i] <= 0) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      reverse(all(a));
      rep(i, n) cout << a[i] << " \n"[i + 1 == n];
    }
  }
}