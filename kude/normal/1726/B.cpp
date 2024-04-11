#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
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
    if (n % 2 == 0) {
      VI ans(n, 1);
      m -= n;
      if (m < 0 || m % 2) {
        cout << "No\n";
        continue;
      }
      m /= 2;
      ans[0] += m;
      ans[1] += m;
      cout << "Yes\n";
      rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    } else {
      VI ans(n, 1);
      m -= n;
      if (m < 0) {
        cout << "No\n";
        continue;
      }
      ans[0] += m;
      cout << "Yes\n";
      rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    }
  }
}