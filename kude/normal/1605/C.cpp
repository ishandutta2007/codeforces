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

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  rep(i, n - 1) {
    if (s[i] == 'a' && s[i + 1] == 'a') {
      cout << 2 << '\n';
      return;
    }
  }
  rep(i, n - 2) {
    if (s[i] == 'a' && s[i + 2] == 'a') {
      cout << 3 << '\n';
      return;
    }
  }
  rep(i, n - 3) {
    if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 1] != s[i + 2]) {
      cout << 4 << '\n';
      return;
    }
  }
  rep(i, n - 6) {
    if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 6] == 'a' && s[i + 1] != s[i + 4]) {
      cout << 7 << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) solve();
}