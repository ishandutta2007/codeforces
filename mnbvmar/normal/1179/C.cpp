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

struct SegTree {
  struct Node {
    int total;
    int push;
    int cnt;
    Node() : total(0), push(0), cnt(0) {}
  };

  vector<Node> nodes;
  int base;
  SegTree(int n) : base(1) {
    while (base < n + 2) { base *= 2; }
    nodes.resize(base * 2);
  }

  void Touch(int v) {
    if (v < base) {
      for (int s : {v*2, v*2+1}) {
        nodes[s].total += nodes[v].push;
        nodes[s].push += nodes[v].push;
      }
    }
    nodes[v].push = 0;
  }

  int lq, rq, valq;


  void AddIntvRec(int lbase, int rbase, int v) {
    if (lbase >= rq || rbase <= lq) { return; }
    Touch(v);
    if (lq <= lbase && rbase <= rq) {
      nodes[v].total += valq;
      nodes[v].push += valq;
      return;
    }

    const int mid = (lbase + rbase) / 2;
    AddIntvRec(lbase, mid, v * 2);
    AddIntvRec(mid, rbase, v * 2 + 1);
    nodes[v].total = max(nodes[v*2].total, nodes[v*2+1].total);
  }

  void AddIntv(int L, int R, int v) {
    if (L >= R) { return; }
    debug("Add", L, R, v);

    lq = L; rq = R; valq = v;
    AddIntvRec(0, base, 1);
  }

  void SetActive(int v, int cnt) {
    v += base;
    while (v) {
      nodes[v].cnt += cnt;
      v /= 2;
    }
  }

  int FindFirstActive() {
    if (nodes[1].total <= 0) { return -1; }

    int r = 1;
    while (r < base) {
      assert(nodes[r].total > 0 && nodes[r].cnt);
      Touch(r);
      if (nodes[r * 2 + 1].total > 0 && nodes[r * 2 + 1].cnt) {
        r = r * 2 + 1;
      } else {
        r *= 2;
      }
    }
    return r - base;
  }
};

int32_t main() {
  int n, m;
  scanf("%d%d", &n, &m);

  vi all_dishes;

  vi dishes(n), pupils(m);
  for (int &x : dishes) { scanf("%d", &x); }
  for (int &x : pupils) { scanf("%d", &x); }
  
  all_dishes = dishes;

  int q;
  scanf("%d", &q);
  vector<vi> queries(q);

  for (int i = 0; i < q; ++i) {
    queries[i].resize(3);
    for (int &x : queries[i]) { scanf("%d", &x); }
    if (queries[i][0] == 1) {
      all_dishes.PB(queries[i][2]);
    }
  }

  sort(ALL(all_dishes));
  all_dishes.resize(unique(ALL(all_dishes)) - all_dishes.begin());

  debug(all_dishes);

  const int S = SZ(all_dishes);
  SegTree tree(S);

  for (int i = 0; i < n; ++i) {
    const int loc = lower_bound(ALL(all_dishes), dishes[i]) - all_dishes.begin();
    tree.AddIntv(0, loc+1, 1);
    tree.SetActive(loc, 1);
  }
  for (int i = 0; i < m; ++i) {
    const int loc = upper_bound(ALL(all_dishes), pupils[i]) - all_dishes.begin();
    tree.AddIntv(0, loc, -1);
  }

  for (int i = 0; i < q; ++i) {
    const int c = queries[i][1] - 1;
    const int x = queries[i][2];
    if (queries[i][0] == 1) {
      int loc = lower_bound(ALL(all_dishes), dishes[c]) - all_dishes.begin();
      tree.AddIntv(0, loc+1, -1);
      tree.SetActive(loc, -1);

      dishes[c] = x;
      loc = lower_bound(ALL(all_dishes), dishes[c]) - all_dishes.begin();
      tree.AddIntv(0, loc+1, 1);
      tree.SetActive(loc, 1);
    } else {
      int loc = upper_bound(ALL(all_dishes), pupils[c]) - all_dishes.begin();
      tree.AddIntv(0, loc, 1);

      pupils[c] = x;
      loc = upper_bound(ALL(all_dishes), pupils[c]) - all_dishes.begin();
      tree.AddIntv(0, loc, -1);
    }

    int a = tree.FindFirstActive();
    if (a != -1) { a = all_dishes[a]; }
    printf("%d\n", a);
  }
}