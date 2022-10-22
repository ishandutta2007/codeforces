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
    string t;
    cin >> t;
    string s;
    for(int i = n - 1; i >= 0;) {
      if (t[i] == '0') {
        s += 'a' + ((t[i-1] - '0') + (t[i-2] - '0') * 10 - 1);
        i -= 3;
      } else {
        s += 'a' + (t[i] - '0' - 1);
        i -= 1;
      }
    }
    reverse(all(s));
    cout << s << '\n';
  }
}