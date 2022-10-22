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

constexpr int MX = 200000;
int hist[MX];

bool cmp(ll n1, ll d1, ll n2, ll d2) {
  return n1 * d2 < n2 * d1;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VI m(n), k(n);
  rep(i, n) cin >> m[i] >> k[i], m[i]--;
  int smx = 0, tmx = 1;
  for(int t = 1; t < 20; t++) {
    rep(i, MX) hist[i] = 0;
    rep(i, n) hist[m[i]] += min(t, k[i]);
    priority_queue<int> q;
    rep(i, MX) q.emplace(hist[i]);
    ll s = 0;
    rep(_, t) {
      s += q.top(), q.pop();
    }
    if (cmp(smx, tmx, s, t)) {
      smx = s;
      tmx = t;
    }
  }
  {
    rep(i, MX) hist[i] = 0;
    rep(i, n) hist[m[i]] += k[i];
    priority_queue<int> q;
    rep(i, MX) q.emplace(hist[i]);
    ll s = 0;
    rep(_, 19) s += q.top(), q.pop();
    for(int t = 20; t <= MX; t++) {
      s += q.top(), q.pop();
      if (cmp(smx, tmx, s, t)) {
        smx = s;
        tmx = t;
      }
    }
  }
  VI ans;
  {
    rep(i, MX) hist[i] = 0;
    rep(i, n) hist[m[i]] += min(tmx, k[i]);
    auto mycmp = [&](int i, int j) {
      return hist[i] < hist[j];
    };
    priority_queue<int, VI, decltype(mycmp)> q(mycmp);
    rep(i, MX) q.emplace(i);
    rep(_, tmx) ans.push_back(q.top()), q.pop();
  }
  cout << tmx << '\n';
  rep(i, tmx) cout << ans[i] + 1 << " \n"[i + 1 == tmx];
}