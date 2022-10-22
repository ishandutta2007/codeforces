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
    string t;
    int to[26]{};
    rep(i, 26) to[i] = -1;

    for(char c: s) {
      int x = c - 'a';
      if (to[x] != -1) {
        t += 'a' + to[x];
        continue;
      }
      bool is_tail[26];
      rep(i, 26) is_tail[i] = true;
      rep(i, 26) if (to[i] != -1) is_tail[to[i]] = false;
      rep(i, 26) if (is_tail[i]) {
        int v = i;
        int s = 1;
        while(to[v] != -1) {
          v = to[v];
          s++;
        }
        if (s == 26 || v != x) {
          to[x] = i;
          break;
        }
      }
      t += 'a' + to[x];
    }
    cout << t << '\n';
  }
}