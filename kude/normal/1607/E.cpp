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
    string s;
    cin >> s;
    int xmin = 0, xmax = 0, ymin = 0, ymax = 0, x = 0, y = 0;
    for(char c: s) {
      if (c == 'L') {
        y--;
        if (y < ymin) {
          if (ymax - y + 1 > m) break;
          ymin = y;
        }
      } else if (c == 'R') {
        y++;
        if (y > ymax) {
          if (y - ymin + 1 > m) break;
          ymax = y;
        }
      } else if (c == 'D') {
        x++;
        if (x > xmax) {
          if (x - xmin + 1 > n) break;
          xmax = x;
        }
      } else {
        x--;
        if (x < xmin) {
          if (xmax - x + 1 > n) break;
          xmin = x;
        }
      }
    }
    int sx = -xmin, sy = -ymin;
    cout << sx + 1 << ' ' << sy + 1 << '\n';
  }
}