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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int p = 0;
    while(p < n && s[p] - 'a' <= k) p++;
    if (p) {
      char mx = *max_element(s.begin(), s.begin() + p);
      k -= mx - 'a';
      rep(i, n) if (s[i] <= mx) s[i] = 'a';
    }
    if (p != n) {
      char from = s[p], to = s[p] - k;
      rep(i, n) if (to <= s[i] && s[i] <= from) {
        s[i] = to;
      }
    }
    cout << s << '\n';
  }
}