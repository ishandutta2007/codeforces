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

bool check(ll x, ll y) {
  VI dx, dy;
  while(x) dx.push_back(x & 1), x >>= 1;
  while(y) dy.push_back(y & 1), y >>= 1;
  rep(_, 2) {
    const int n = dx.size(), m = dy.size();
    for(int i = 0; i <= m - n; i++) {
      bool ok = true;
      rep(j, i) if (dy[j] == 0) ok = false;
      for(int j = i + n; j < m; j++) if (dy[j] == 0) ok = false;
      rep(j, n) if (dy[i + j] != dx[j]) ok = false;
      if (ok) return true;
    }
    reverse(all(dx));
  }
  return false;
}


} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES\n";
    return 0;
  }
  cout << (check(x / (x & -x), y) || check(2 * x + 1, y) ? "YES\n" : "NO\n");
}