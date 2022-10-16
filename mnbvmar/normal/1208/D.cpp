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

struct Tree {
  struct Node {
    ll min, push;
    Node():min(0),push(0){}
  };
  vector<Node> nodes; int base;
  Tree(int n) : base(1) { while(base<n+2){base*=2;} nodes.resize(base*2); }

  void Touch(int v) {
    if (v < base) {
      for(int s:{v*2,v*2+1}) {
        nodes[s].min+=nodes[v].push;
        nodes[s].push+=nodes[v].push;
      }
      nodes[v].push = 0;
    }
  }

  void Add(int L, int R, int lbase, int rbase, int v, ll value) {
    if (rbase == base) { debug(L,R,v,value); }
    if (rbase <= L || lbase >= R) { return; }
    if (L <= lbase && rbase <= R) {
      nodes[v].push += value;
      nodes[v].min += value;
      return;
    }
    Touch(v);
    const int mid = (lbase+rbase)/2;
    Add(L,R,lbase,mid,v*2,value);
    Add(L,R,mid,rbase,v*2+1,value);
    nodes[v].min = min(nodes[v*2].min, nodes[v*2+1].min);
  }

  int WhereMin() {
    int ptr = 1;
    ll ans = nodes[1].min;
    debug(ans);

    while (ptr < base) {
      Touch(ptr);
      if (nodes[ptr*2+1].min == ans) {
        ptr = ptr*2+1;
      } else {
        ptr *= 2;
      }
    }
    return ptr - base;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  int n;
  cin >> n;

  vll sums(n);
  for (ll &x : sums) { cin >> x; }

  Tree tree(n);
  for (int i = 0; i < n; ++i) {
    tree.Add(i, i + 1, 0, tree.base, 1, sums[i]);
  }
  tree.Add(n, tree.base, 0, tree.base, 1, (ll)n * n);

  vi ans(n);

  for (int i = 0; i < n; ++i) {
    int where = tree.WhereMin();
    debug(where);
    tree.Add(where, where + 1, 0, tree.base, 1, (ll)n * n);
    tree.Add(where + 1, tree.base, 0, tree.base, 1, -(i+1));
    ans[where] = i + 1;
  }
  for (int x : ans) { cout << x << " "; }
  cout << "\n";
}