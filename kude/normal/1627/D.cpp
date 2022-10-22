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

constexpr int MX = 1000000;
bool dp[MX + 1];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  rep(i, n) {
    int x;
    cin >> x;
    dp[x] = true;
  }
  rrep(i, MX + 1) if (i && !dp[i]) {
    int g = 0;
    for(int j = 2 * i; j <= MX; j += i) if (dp[j]) {
      g = gcd(g, j);
      if (g == i) {
        dp[i] = true;
        break;
      }
    }
  }
  int tot = 0;
  rep(i, MX + 1) tot += dp[i];
  cout << tot - n << '\n';
}