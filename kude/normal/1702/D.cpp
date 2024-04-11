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
    string s;
    cin >> s;
    int n = s.size();
    int p;
    cin >> p;
    vector<char> remove(n);
    int now = 0;
    for(char c: s) now += c - 'a' + 1;
    vector<P> elems(n);
    rep(i, n) elems[i] = {s[i] - 'a' + 1, i};
    sort(rall(elems));
    for(auto [x, i]: elems) {
      if (now <= p) break;
      now -= x;
      remove[i] = true;
    }
    string ans;
    rep(i, n) if (!remove[i]) ans += s[i];
    cout << ans << '\n';
  }
}