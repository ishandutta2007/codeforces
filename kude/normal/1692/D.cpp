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
    string ss;
    cin >> ss;
    int x;
    cin >> x;
    int s = ((ss[0] - '0') * 10 + (ss[1] - '0')) * 60 +
             (ss[3] - '0') * 10 + (ss[4] - '0');
    int t = s;
    int ans = 0;
    do {
      int h = t / 60, m = t % 60;
      if (h / 10 == m % 10 && h % 10 == m / 10) ans++;
      t += x;
      t %= 24 * 60;
    } while(t != s);
    cout << ans << '\n';
  }
}