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
    string s;
    cin >> s;
    bool has[3] = {};
    bool ok = true;
    for(char c: s) {
      if (c == 'r') has[0] = true;
      else if (c == 'g') has[1] = true;
      else if (c == 'b') has[2] = true;
      else if (c == 'R') {
        if (!has[0]) ok = false;
      } else if (c == 'G') {
        if (!has[1]) ok = false;
      } else {
        assert(c == 'B');
        if (!has[2]) ok = false;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}