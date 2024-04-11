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

int hist[200010];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    rep(i, n + 1) hist[i] = 0;
    rep(_, n) {
      int x;
      cin >> x;
      hist[x]++;
    }
    priority_queue<int> q;
    ll acc = 0;
    for(int i = 0; i <= n; i++) {
      if (i > 0 && hist[i - 1] == 0) {
        if (q.empty()) {
          for(; i <= n; i++) {
            cout << -1 << " \n"[i == n];
          }
          break;
        }
        acc += i - 1 - q.top(); q.pop();
      }
      ll ans = acc + hist[i];
      cout << ans << " \n"[i == n];
      while(hist[i] > 1) q.push(i), hist[i]--;
    }
  }
}