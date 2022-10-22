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

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i], a[i]--;
    string s;
    cin >> s;
    bool ok = true;
    VVI evs(n);
    rep(i, n) {
      if (s[i] == 'B') {
        chmin(a[i], n - 1);
        if (a[i] < 0) {
          ok = false;
          break;
        }
        evs[0].push_back(a[i] + 1);
      } else {
        chmax(a[i], 0);
        if (a[i] >= n) {
          ok = false;
          break;
        }
        evs[a[i]].push_back(n);
      }
    }
    priority_queue<int, VI, greater<int>> q;
    rep(i, n) {
      for(int r: evs[i]) q.push(r);
      if (q.empty() || q.top() <= i) {
        ok = false;
        break;
      } else {
        q.pop();
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}