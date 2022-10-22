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

bool alarm[24 * 60];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, h, m;
    cin >> n >> h >> m;
    memset(alarm, 0, sizeof(alarm));
    rep(_, n) {
      int h, m;
      cin >> h >> m;
      alarm[60 * h + m] = true;
    }
    int t = 60 * h + m;
    int ans = 0;
    while(!alarm[t]) {
      ans++;
      t++;
      if (t == 24 * 60) t = 0;
    }
    cout << ans / 60 << ' ' << ans % 60 << '\n';
  }
}