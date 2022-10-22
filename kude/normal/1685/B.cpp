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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = a + b + 2 * c + 2 * d;
    string s;
    cin >> s;
    int acnt = 0, bcnt = 0;
    for(char c: s) (c == 'A' ? acnt : bcnt)++;
    if (acnt != a + c + d || bcnt != b + c + d) {
      cout << "NO\n";
      continue;
    }
    priority_queue<P, vector<P>, greater<P>> q;
    for(int i = 0; i < n;) {
      int j = i + 1;
      while(j < n && s[j] != s[j - 1]) j++;
      int cnt = j - i;
      if (cnt % 2 == 0) {
        if (s[i] == 'A') {
          q.emplace(0, cnt / 2);
        } else {
          q.emplace(2, -cnt / 2);
        }
      } else if (cnt > 1) {
        q.emplace(1, cnt / 2);
      }
      i = j;
    }
    while(q.size()) {
      auto [t, cnt] = q.top(); q.pop();
      if (t == 0) {
        int v = min(cnt, c);
        c -= v;
        cnt -= v;
        if (cnt) d -= cnt - 1;
      } else if (t == 1) {
        int v = min(cnt, c);
        c -= v;
        cnt -= v;
        d -= cnt;
      } else {
        cnt = -cnt;
        if (c) {
          cnt--;
          int v = min(cnt, c);
          cnt -= v;
          c -= v;
        }
        d -= cnt;
      }
    }
    cout << (c == 0 && d <= 0 ? "YES\n" : "NO\n");
  }
}