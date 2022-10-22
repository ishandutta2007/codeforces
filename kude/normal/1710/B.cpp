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
    int n, m;
    cin >> n >> m;
    VI x(n), p(n);
    vector<P> evs1;
    rep(i, n) {
      cin >> x[i] >> p[i];
      evs1.emplace_back(x[i] - p[i], 1);
      evs1.emplace_back(x[i], -2);
      evs1.emplace_back(x[i] + p[i], 1);
    }
    sort(all(evs1));
    ll a = 0, b = 0;
    vector<pair<int, ll>> evs2;
    multiset<ll> st1, st2;
    for (auto [x0, c]: evs1) {
      a += c;
      b += -ll(c) * x0;
      ll y = a * x0 + b;
      if (y > m) {
        ll d = y - m;
        evs2.emplace_back(x0, d);
        st1.emplace(x0 + d);
      }
    }
    sort(rall(evs2));
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
      return x[i] < x[j];
    });
    vector<char> ans(n);
    for(int i: ord) {
      while(!evs2.empty() && evs2.back().first < x[i]) {
        auto [x0, d] = evs2.back(); evs2.pop_back();
        st1.erase(st1.find(x0 + d));
        st2.emplace(-x0 + d);
      }
      bool ok = true;
      if (!st1.empty()) {
        if (p[i] < -x[i] + *st1.rbegin()) {
          ok = false;
        }
      }
      if (ok && !st2.empty()) {
        if (p[i] < x[i] + *st2.rbegin()) {
          ok = false;
        }
      }
      ans[i] = ok;
    }
    rep(i, n) cout << "01"[ans[i]];
    cout << '\n';
  }
}