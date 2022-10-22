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

constexpr int MX = 1000000 * 19 + 1;
bool d[MX];
int c[20];

bool done[1000001];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= 19; i++) {
    for(int j = i, it = 1; it <= m; j += i, it++) {
      d[j] = true;
    }
    c[i] = accumulate(d, d + MX, 0);
  }
  ll ans = 1;
  for(int i = 2; i <= n; i++) if (!done[i]) {
    int cnt = 0;
    for(ll j = i; j <= n; j *= i) {
      cnt++;
      done[j] = true;
    }
    ans += c[cnt];
  }
  cout << ans << '\n';
}