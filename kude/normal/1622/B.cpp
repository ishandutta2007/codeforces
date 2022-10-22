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
    VI p(n);
    rep(i, n) cin >> p[i];
    string s;
    cin >> s;
    VI ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
      return P{s[i], p[i]} < P{s[j], p[j]};
    });
    VI q(n);
    rep(i, n) q[ord[i]] = i + 1;
    rep(i, n) cout << q[i] << " \n"[i + 1 == n];
  }
}