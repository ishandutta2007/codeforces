#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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

struct Tree {
  struct Node {
    LL min_val;
    LL push;
    Node() : min_val(0), push(0) {}
  };

  vector<Node> nodes;
  int base;

  Tree(int N) : base(1) {
    while (base < N + 3) { base *= 2; }
    nodes.resize(base * 2);
  }

  void Push(int v) {
    if (v < base) {
      for (int s : {v * 2, v * 2 + 1}) {
        nodes[s].min_val += nodes[v].push;
        nodes[s].push += nodes[v].push;
      }
      nodes[v].push = 0;
    }
  }

  int lq, rq;
  LL vq;

  void AddRec(int lbase, int rbase, int v) {
    if (lbase >= rq || rbase <= lq) { return; }
    Push(v);
    if (lq <= lbase && rbase <= rq) {
      nodes[v].min_val += vq;
      nodes[v].push += vq;
      return;
    }

    const int m = (lbase + rbase) / 2;
    AddRec(lbase, m, v * 2);
    AddRec(m, rbase, v * 2 + 1);
    nodes[v].min_val = min(nodes[v * 2].min_val, nodes[v * 2 + 1].min_val);
  }

  void Add(int L, int R, LL val) {
    debug("Add", L, R, val);
    lq = L; rq = R; vq = val;
    AddRec(0, base, 1);
  }

  LL GetMinRec(int lbase, int rbase, int v) {
    if (lbase >= rq || rbase <= lq) { return 1e18; }
    Push(v);
    if (lq <= lbase && rbase <= rq) {
      return nodes[v].min_val;
    }

    const int m = (lbase + rbase) / 2;
    return min(GetMinRec(lbase, m, v * 2), GetMinRec(m, rbase, v * 2 + 1));
  }

  LL GetMin(int L, int R) {
    lq = L; rq = R;
    LL ans = GetMinRec(0, base, 1);
    debug("Min", L, R, ans);
    return ans;
  }
};

const int MaxN = 5e5 + 100;

int N, Q;
vector<PII> children[MaxN];
vector<tuple<int, int, int>> queries[MaxN];
LL answers[MaxN];
LL depths[MaxN];
int postorder[MaxN];
int cur_tm = 0;

unique_ptr<Tree> tree;

void DfsPostorder(int v) {
  ++cur_tm;
  assert(v == cur_tm);
  for (auto &edge : children[v]) {
    DfsPostorder(edge.st);
  }
  postorder[v] = cur_tm;
  debug(v, postorder[v]);
}

LL whole_incr = 0;

void DfsQueries(int v) {
  for (auto &&[l, r, idx] : queries[v]) {
    answers[idx] = tree->GetMin(l, r + 1) + whole_incr;
  }

  for (auto &&[s, c] : children[v]) {
    const int L = s;
    const int R = postorder[s];
    whole_incr += c;
    //tree->Add(1, N + 1, c);
    tree->Add(L, R + 1, -2 * c);
    DfsQueries(s);
    whole_incr -= c;
    //tree->Add(1, N + 1, -c);
    tree->Add(L, R + 1, 2 * c);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> Q;
  for (int i = 2; i <= N; ++i) {
    int p, w;
    cin >> p >> w;
    children[p].emplace_back(i, w);
    depths[i] = depths[p] + w;
  }

  tree = make_unique<Tree>(N + 5);
  for (int i = 1; i <= N; ++i) {
    if (SZ(children[i]) != 0) { depths[i] = 1e18; }
    tree->Add(i, i + 1, depths[i]);
  }

  for (int i = 0; i < Q; ++i) {
    int v, l, r;
    cin >> v >> l >> r;
    queries[v].emplace_back(l, r, i);
  }

  DfsPostorder(1);
  DfsQueries(1);

  for (int i = 0; i < Q; ++i) {
    cout << answers[i] << "\n";
  }
}