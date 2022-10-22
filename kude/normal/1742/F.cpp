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

template <class T, class C = long long>
struct run_length_encoding {
  vector<pair<T, C>> d;

  run_length_encoding() {}
  template <class Iter>
  run_length_encoding(Iter first, Iter last) {
    while (first != last) {
      auto v = *first++;
      int cnt = 1;
      while (first != last && *first == v) {
        first++;
        cnt++;
      }
      d.emplace_back(v, cnt);
    }
  }
  void push_back(T v, C count) {
    assert(count >= 0);
    if (count == 0) return;
    if (!d.empty() && d.back().first == v) {
      d.back().second += count;
    } else {
      d.emplace_back(v, count);
    }
  }
  bool operator<(const run_length_encoding& rhs) const {
    int i = 0;
    int ub = min(d.size(), rhs.d.size());
    while (i < ub && d[i] == rhs.d[i]) i++;
    if (i == ub) return d.size() < rhs.d.size();
    auto [vl, cl] = d[i];
    auto [vr, cr] = rhs.d[i];
    if (vl != vr) return vl < vr;
    if (cl < cr) {
      return i + 1 == int(d.size()) || d[i + 1].first < vr;
    } else {
      return i + 1 < int(rhs.d.size()) && vl < rhs.d[i + 1].first;
    }
  }
};

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int q;
    cin >> q;
    ll cs[26]{1}, ct[26]{1};
    rep(_, q) {
      int d, k;
      cin >> d >> k;
      string x;
      cin >> x;
      for(char c: x) (d == 1 ? cs : ct)[c - 'a'] += k;
      run_length_encoding<char, ll> ds, dt;
      rep(i, 26) ds.push_back(i, cs[i]);
      rrep(i, 26) dt.push_back(i, ct[i]);
      cout << (ds < dt ? "YES\n" : "NO\n");
    }
  }
}