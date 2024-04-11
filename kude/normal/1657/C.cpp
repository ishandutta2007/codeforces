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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    int ans = 0;
    while(true) {
      if (i + 1 < n) {
        if (s[i] == s[i + 1]) {
          ans++;
          i += 2;
          continue;
        } else if (s[i] == '(') {
          ans++;
          i += 2;
          continue;
        } else {
          int j = i + 2;
          while(j < n && s[j] != ')') j++;
          if (j == n) break;
          ans++;
          i = j + 1;
        }
      } else {
        break;
      }
    }
    cout << ans << ' ' << n - i << '\n';
  }
}