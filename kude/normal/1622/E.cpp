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

bool s[10][10000];
int x[10];
int tmp[10000];
int hist[21];
int ans[10000];
int ptr[21];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    rep(i, n) cin >> x[i];
    rep(i, n) rep(j, m) {
      char c;
      cin >> c;
      s[i][j] = c == '1';
    }
    ll mx = -1;
    rep(b, 1 << n) {
      memset(tmp, 0, sizeof(int) * m);
      ll sm = 0;
      rep(i, n) {
        if (b >> i & 1) {
          sm += x[i];
          rep(j, m) tmp[j] -= s[i][j];
        } else {
          sm -= x[i];
          rep(j, m) tmp[j] += s[i][j];
        }
      }
      memset(hist, 0, sizeof(int) * 21);
      rep(j, m) hist[tmp[j] + 10]++;
      ptr[0] = 0;
      rep(i, 20) ptr[i + 1] = ptr[i] + hist[i];
      // cout << sm << endl;
      rep(j, m) {
        // cout << tmp[j] << ' ' << ptr[tmp[j] + 10] << " \n"[j + 1 == m];
        sm += tmp[j] * (ptr[tmp[j] + 10]++ + 1);
      }
      // cout << sm << endl;
      // exit(0);
      if (sm > mx) {
        mx = sm;
        ptr[0] = 0;
        rep(i, 20) ptr[i + 1] = ptr[i] + hist[i];
        rep(j, m) ans[j] = ptr[tmp[j] + 10]++ + 1;
      }
    }
    // cout << mx << '\n';
    rep(j, m) cout << ans[j] << " \n"[j + 1 == m];
  }
}