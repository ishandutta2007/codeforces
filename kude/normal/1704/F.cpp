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

int d[] = {0,0,1,1,2,0,3,1,1,0,3,3,2,2,4,0,5,2,2,3,3,0,1,1,3,0,2,1,1,0,4,5,2,7,4,0,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,2,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7};
int d2[] = {4,8,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,9,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7,4,8,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,9,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7};

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  constexpr int MX = 500010;
  int len = sizeof(d) / sizeof(int);
  VI g(MX);
  rep(i, MX) {
    if (i < len) g[i] = d[i];
    else g[i] = d2[i % len];
  }
  // vector<char> seen(MX);
  // for(int i = 2; i < MX; i++) {
  //   for(int j = 0, k = i - 2; j <= k; j++, k--) {
  //     seen[g[j]^g[k]] = true;
  //   }
  //   int x = 0;
  //   while(seen[x]) x++;
  //   g[i] = x;
  //   for(int j = 0, k = i - 2; j <= k; j++, k--) {
  //     seen[g[j]^g[k]] = false;
  //   }
  // }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0;
    for(int i = 0; i < n;) {
      int j = i + 1;
      while(j < n && s[j] != s[j - 1]) j++;
      x ^= g[j - i];
      i = j;
    }
    int ans = 0;
    if (x) ans++;
    rep(i, n) {
      if (s[i] == 'R') ans++;
      else ans--;
    }
    cout << (ans > 0 ? "Alice\n" : "Bob\n");
  }
}