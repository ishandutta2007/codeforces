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
    string s;
    cin >> s;
    VI r0(n + 1), l1(n + 1);
    rep(i, n) l1[i + 1] = l1[i] + (s[i] == '1');
    rrep(i, n) r0[i] = r0[i + 1] + (s[i] == '0');
    rep(c, n + 1) if (l1[c] == r0[c]) {
      if (l1[c] == 0) {
        cout << 0 << '\n';
      } else {
        cout << 1 << '\n';
        cout << 2 * l1[c];
        rep(i, c) if (s[i] == '1') cout << ' ' << i + 1;
        for(int i = c; i < n; i++) if (s[i] == '0') cout << ' ' << i + 1;
        cout << '\n';
      }
      break;
    }
  }
}