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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == 'R') {
      for(char& c: s) c ^= 'R' ^ 'D';
    }
    int x = 0, y = 0;
    for(char c: s) {
      if (c == 'D') x++;
      else y++;
    }
    ll lx = n - x, ly = n - y;
    if (y == 0) {
      cout << n << '\n';
      continue;
    }
    int i0 = find(all(s), 'R') - s.begin();
    ll ans = i0 + lx;
    ans += lx * ly;
    for(int i = i0 + 1; i < s.size(); i++) {
      if (s[i] == 'D') ans += ly;
      else ans += lx;
    }
    cout << ans << '\n';
  }
}