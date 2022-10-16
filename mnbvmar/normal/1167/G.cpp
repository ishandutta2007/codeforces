#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
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


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int n, d;
  cin >> n >> d;

  vector<int> locs(n);
  for (int &x : locs) { cin >> x; }
  vector<int> dot_locs;

  int m;
  cin >> m;
  vector<int> queries(m);
  for (int &x : queries) { cin >> x; }

  const LD kPi = 2 * acos(0);

  const int kMaxRange = 20000;

  bitset<kMaxRange> pref, suf;
  int last_x = 0;
  for (int x : locs) {
    for (int p : {x, x + 1}) {
      dot_locs.PB(p);
      if (p < kMaxRange) { suf[p] = true; }
    }
  }
  dot_locs.PB(-1e7);
  sort(ALL(dot_locs));
  dot_locs.resize(unique(ALL(dot_locs)) - dot_locs.begin());
  dot_locs.PB(2e9);
  int dotptr = 0;

  for (int i = 0; i < m; ++i) {
    const int x = queries[i];
    const int pos_prev = lower_bound(ALL(locs), x) - locs.begin() - 1;
    const int pos_next = pos_prev + 1;

    while (dot_locs[dotptr] < x) { ++dotptr; }

    const int x_diff = x - last_x;
    last_x = x;
    if (x_diff >= kMaxRange) {
      pref.reset();
      suf.reset();
    } else {
      pref <<= x_diff;
      suf >>= x_diff;
    }

    {
      int dl = dotptr - 1;
      while (dl >= 0) {
        const int dx = x - dot_locs[dl];
        if (dx >= kMaxRange || dx > x_diff) { break; }
        pref[dx] = true;
        --dl;
      }

      int dr = lower_bound(ALL(dot_locs), x + kMaxRange) - dot_locs.begin() - 1;
      while (dr >= dotptr) {
        const int dx = dot_locs[dr] - x;
        assert(dx < kMaxRange);
        if (dx < kMaxRange - x_diff) { break; }
        suf[dx] = true;
        --dr;
      }
    }

    debug(x, pref, suf);

    LD ans = 0;

    if (pos_prev >= 0) {
      if (locs[pos_prev] == x - 1) {
        maxi(ans, kPi / 2);
      } else {
        maxi(ans, atan((LD)1 / (x - locs[pos_prev] - 1)));
      }
    }

    if (pos_next < n) {
      if (locs[pos_next] == x) {
        maxi(ans, kPi / 2);
      } else {
        maxi(ans, atan((LD)1 / (locs[pos_next] - x)));
      }
    }

    if (pos_prev < 0 || pos_next >= n) {
      cout << ans << "\n";
      continue;
    }

    if (locs[pos_prev] == locs[pos_next] - 1) {
      maxi(ans, kPi);
      cout << ans << "\n";
      continue;
    }

    //debug(x, dotptr, dot_locs);
    auto intersection = pref & suf;
    if (intersection.any()) {
      const int distl = intersection._Find_first();
      maxi(ans, 2 * atan((LD)1 / distl));
    }


    /*int lptr = dotptr - 1, rptr = dotptr;
    while (true) {
      const int distl = x - dot_locs[lptr];
      const int distr = dot_locs[rptr] - x;
      if (distl == distr) {
        maxi(ans, 2 * atan((LD)1 / distl));
        break;
      }

      if (max(distl, distr) > kMaxRange) { break; }

      if (distl < distr) {
        --lptr;
      } else {
        ++rptr;
      }
    }*/

    cout << ans << "\n";
  }
}