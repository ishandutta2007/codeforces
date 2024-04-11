#pragma gcc optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
 
const int MaxN = 2e5 + 100;
const int S = 600;
 
int preorder[MaxN], postorder[MaxN];
vi children[MaxN];
int cur_tm;
 
void DfsPre(int v) {
  preorder[v] = cur_tm++;
  for (int s : children[v]) {
    DfsPre(s);
  }
  postorder[v] = cur_tm;
}
 
ll CrossProd(const pll &a, const pll &b) {
  return a.st * b.nd - a.nd * b.st;
}
 
ll CrossProd(const pll &s, const pll &a, const pll &b) {
  return CrossProd({a.st-s.st, a.nd-s.nd}, {b.st-s.st, b.nd-s.nd});
}
 
struct Hull {
  vector<pll> hull;
  int ptr;
 
  Hull() {}
 
  Hull(vector<pll> lines) { // [(a, b)]
    assert(is_sorted(ALL(lines)));
    //sort(ALL(lines));
    for (int i = 0; i < SZ(lines); ++i) {
      if (i < SZ(lines) - 1 && lines[i].st == lines[i+1].st) { continue; }
      auto &v = lines[i];
      int r = hull.size();
      while (r >= 2 && CrossProd(hull[r-2], hull[r-1], v) >= 0) {
        --r;
        hull.pop_back();
      }
      hull.PB(v);
    }
    ptr = 0;
    debug(lines, hull);
  }
 
  ll MaxAt(int idx, ll x) {
    return hull[idx].st * x + hull[idx].nd;
  }
  
  ll GetMax(ll x) {
    debug(hull, x);
    const int r = hull.size();
    while (ptr < r - 1 && MaxAt(ptr+1, x) >= MaxAt(ptr, x)) { ++ptr; }
    return MaxAt(ptr, x);
  }
};
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
 
  /*int la, lb;
  vector<pll> lines;
  while (cin >> la >> lb) {
    lines.emplace_back(la, lb);
  }
  Hull hull(lines);
  debug(hull.hull);
  return 0;*/
 
  int n, q;
  cin >> n >> q;
  vi pnt(n + 1);
  for (int i = 2; i <= n; ++i) {
    cin >> pnt[i];
    children[pnt[i]].PB(i);
  }
 
  vi in_a(n + 1), in_b(n + 1), in_r(n + 1), in_sa(n + 1);
  for (int i = 1; i <= n; ++i) { cin >> in_a[i]; }
  for (int i = 1; i <= n; ++i) { cin >> in_b[i]; }
  for (int i = 1; i <= n; ++i) {
    in_r[i] = in_b[i] + in_r[pnt[i]];
    in_sa[i] = in_a[i] + in_sa[pnt[i]];
  }
 
  DfsPre(1);
 
  vll a(n), b(n), r(n), sa(n);
  for (int i = 1; i <= n; ++i) {
    a[preorder[i]] = in_a[i];
    b[preorder[i]] = in_b[i];
    r[preorder[i]] = in_r[i];
    sa[preorder[i]] = in_sa[i];
  }
 
  vll cur_val(n);
  for (int i = 0; i < n; ++i) {
    cur_val[i] = (ll)sa[i] * r[i];
  }
 
  const int nbucks = (n + S - 1) / S;
 
  vector<Hull> maxhulls(nbucks), minhulls(nbucks);
  vector<vi> rorder(nbucks);
  vll shiftx(nbucks);
 
  for (int i = 0; i < n; ++i) {
    rorder[i / S].PB(i);
  }
  for (int i = 0; i < nbucks; ++i) {
    sort(ALL(rorder[i]), [&](int lhs, int rhs) {
          return r[lhs] < r[rhs];
        });
  }
 
  auto BuildHull = [&](int idx) {
    debug(idx);
    //const int from = S * idx;
    //const int to = min(n, S * (idx + 1));
    vector<pll> lines;
 
    for (int i : rorder[idx]) {
      if (!lines.empty() && lines.back().st == r[i]) {
        maxi(lines.back().nd, cur_val[i]);
      } else {
        lines.emplace_back(r[i], cur_val[i]);
      }
    }
 
    //for (int i = from; i < to; ++i) {
    //  lines[i - from] = pll(r[i], cur_val[i]);
    //}
    maxhulls[idx] = Hull(lines);
 
    int ptr = 0;
    for (int i : rorder[idx]) {
      while (lines[ptr].st != r[i]) { ++ptr; }
      mini(lines[ptr].nd, cur_val[i]);
    }
 
    for (auto &ln : lines) {
      ln.st = -ln.st; ln.nd = -ln.nd;
    }
    reverse(ALL(lines));
    minhulls[idx] = Hull(lines);
  };
 
  for (int i = 0; i < nbucks; ++i) {
    BuildHull(i);
  }
 
  for (int qid = 0; qid < q; ++qid) {
    int type, v;
    cin >> type >> v;
    const int L = preorder[v], R = postorder[v];
 
    if (type == 1) {
      int x;
      cin >> x;
      a[L] += x;
 
      const int lb = L / S;
      const int rb = (R - 1) / S;
      auto Rebuild = [&](int buck) {
        //const int bfrom = S * buck;
        //const int bto = S * (buck + 1);
 
        const int from = max(L, S * buck);
        const int to = min(R, S * (buck + 1));
        for (int i = from; i < to; ++i) {
          cur_val[i] += x * r[i];
        }
 
        BuildHull(buck);
      };
 
      Rebuild(lb);
      if (lb != rb) { Rebuild(rb); }
 
      for (int i = lb + 1; i < rb; ++i) {
        shiftx[i] += x;
      }
 
      /* for (int i = L; i < R; ++i) {
        cur_val[i] += x * r[i];
      } */
    } else {
 
      const int lb = L / S;
      const int rb = (R - 1) / S;
 
      ll ans = 0;
 
      for (int x : {lb, rb}) {
        const int from = max(L, S * x);
        const int to = min(R, S * (x + 1));
        
        for (int i = from; i < to; ++i) {
          maxi(ans, abs(cur_val[i] + shiftx[x] * r[i]));
        }
      }
 
      for (int i = lb + 1; i < rb; ++i) {
        maxi(ans, abs(maxhulls[i].GetMax(shiftx[i])));
        maxi(ans, abs(minhulls[i].GetMax(shiftx[i])));
      }
 
      cout << ans << "\n";
 
      /*ll mn = 1e18, mx = -1e18;
      for (int i = L; i < R; ++i) {
        mini(mn, cur_val[i]);
        maxi(mx, cur_val[i]);
      }*/
      //cout << max(abs(mn), abs(mx)) << "\n";
    }
 
    debug(cur_val);
  }
}