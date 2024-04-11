#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ld = long double;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  int n, w;
  cin >> n >> w;

  vll ans(w), pref(w + 1);

  for (int x = 0; x < n; ++x) {
    int len; cin >> len;
    vi elems(len); for (int &x : elems) { cin >> x; }

    if (len * 2 >= w) {
      vi decr{(int)2e9};
      vi loc{-1};
      int start = 1;
      int drop = 0;
      for (int i = 0; i < w; ++i) {
        if (i < len) {
          while (SZ(decr) > start && decr.back() < elems[i]) {
            decr.pop_back();
            loc.pop_back();
          }
          decr.PB(elems[i]);
          loc.PB(i);
        }
        debug(i, decr, loc, start);
        int add = decr[start];
        if (max(i, w-i-1) >= len) { maxi(add, 0); }
        ans[i] += add;
        if (i >= w - len) {
          if (SZ(decr) > start && loc[start] == drop) {
            ++start;
          }
          ++drop;
        }
      }

    } else {
      int cur = -2e9;
      for (int i = 0; i < len; ++i) {
        maxi(cur, elems[i]);
        ans[i] += max(0,cur);
      }
      cur = -2e9;
      for (int i = 0; i < len; ++i) {
        maxi(cur, elems[len - i - 1]);
        ans[w - i - 1] += max(0, cur);
      }
      maxi(cur, 0);
      pref[len] += cur;
      pref[w - len] -= cur;
    }
  }

  for (int i = 1; i < w; ++i) {
    pref[i] += pref[i - 1];
    ans[i] += pref[i];
  }
  for (int i = 0; i < w; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}