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
  VI idx[26];
  while(tt--) {
    rep(i, 26) idx[i].clear();
    string s;
    cin >> s;
    int n = s.size();
    rep(i, n) idx[s[i] - 'a'].emplace_back(i);
    int first = s[0] - 'a';
    int last = s[n-1] - 'a';
    int cost = abs(first - last);
    VI ans;
    auto f = [&](int i) { ans.insert(ans.end(), all(idx[i])); };
    while(first < last) f(first++);
    while(first > last) f(first--);
    f(first);
    int m = ans.size();
    cout << cost << ' ' << m << '\n';
    rep(i, m) cout << ans[i] + 1 << " \n"[i + 1 == m];
  }
}