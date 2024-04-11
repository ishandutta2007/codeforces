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
    ll mxval;
    ll push;
    
    Node() : mxval(0), push(0) {}
  };
  
  vector<Node> nodes;
  int base;
  
  SegTree(int n) : base(1) {
    while (base < n + 2) { base *= 2; }
    nodes.resize(base * 2);
  }
  
  int lq, rq;
  ll valq;
  
  void Touch(int v) {
    if (v < base) {
      for (int s : {v * 2, v * 2 + 1}) {
        nodes[s].mxval += nodes[v].push;
        nodes[s].push += nodes[v].push;
      }
    }
    nodes[v].push = 0;
  }
  
  void AddIntvRec(int lbase, int rbase, int v) {
    if (lbase >= rq || rbase <= lq) { return; }
    if (lq <= lbase && rbase <= rq) {
      nodes[v].mxval += valq;
      nodes[v].push += valq;
      return;
    }
    Touch(v);
    const int mid = (lbase + rbase) / 2;
    AddIntvRec(lbase, mid, v * 2);
    AddIntvRec(mid, rbase, v * 2 + 1);
    nodes[v].mxval = max(nodes[v * 2].mxval, nodes[v * 2 + 1].mxval);
  }
  
  void AddIntv(int L, int R, ll val) {
    lq = L; rq = R; valq = val; AddIntvRec(0, base, 1);
  }
  
  ll GetMaxRec(int lbase, int rbase, int v) {
    if (lbase >= rq || rbase <= lq) { return -4e18; }
    if (lq <= lbase && rbase <= rq) { return nodes[v].mxval; }
    Touch(v);
    const int mid = (lbase + rbase) / 2;
    return max(GetMaxRec(lbase, mid, v * 2),
               GetMaxRec(mid, rbase, v * 2 + 1));
  }
  
  ll GetMax(int L, int R) {
    lq = L; rq = R; return GetMaxRec(0, base, 1);
  }
};

struct CentroidParentInfo {
  int vert;
  int pre, post;
  int subtree_idx;
};

struct CentroidInfo {
  vector<pii> sub_intvs;
  multiset<ll> max_dists;
  unique_ptr<SegTree> tree;
};

const int kMaxN = 1e5 + 100;

int n, q;
ll maxw;

vector<tuple<int, int, int, int>> edges;
vector<pair<int, ll>> adj[kMaxN];
bool is_forbidden[kMaxN];

vector<CentroidParentInfo> centr_pts[kMaxN];
CentroidInfo centr_info[kMaxN];
multiset<ll> declared_ans;

int pretm;
int ccc;

void MakePreDfs(int v, int p, int subidx) {
  CentroidParentInfo pnt_info{ccc, pretm++, 0, subidx};
  for (auto &&[s, c] : adj[v]) {
    (void)c;
    if (s == p || is_forbidden[s]) { continue; }
    MakePreDfs(s, v, subidx);
  }
  pnt_info.post = pretm;
  centr_pts[v].push_back(pnt_info);
}

void PopulateSegDfs(int v, int p, int centr) {
  for (auto &&[s, c] : adj[v]) {
    if (s == p || is_forbidden[s]) { continue; }
    const int pre = centr_pts[s].back().pre;
    const int post = centr_pts[s].back().post;
    centr_info[centr].tree->AddIntv(pre, post, c);
    PopulateSegDfs(s, v, centr);
  }
}

inline ll ReadAns(int v) {
  auto &m = centr_info[v].max_dists;
  if (m.empty()) { return 0; }
  if (SZ(m) == 1) { return *m.rbegin(); }
  auto iter = prev(m.end());
  return *iter + *prev(iter);
}

void PreprocCentroid(int centr) {
  pretm = 0;
  int subidx = 0;
  ccc = centr;
  for (auto &edge : adj[centr]) {
    const int s = edge.st;
    if (is_forbidden[s]) { continue; }
    const int start_tm = pretm;
    MakePreDfs(s, centr, subidx);
    centr_info[centr].sub_intvs.emplace_back(start_tm, pretm);
    
    ++subidx;
  }
  
  const int sz = pretm;
  centr_info[centr].tree = make_unique<SegTree>(sz);
  PopulateSegDfs(centr, centr, centr);
  
  centr_pts[centr].PB(CentroidParentInfo{centr, -1, sz + 1, -1});
  
  for (auto &&[L, R] : centr_info[centr].sub_intvs) {
    centr_info[centr].max_dists.insert(centr_info[centr].tree->GetMax(L, R));
  }
  
  declared_ans.insert(ReadAns(centr));
}

int tree_size[kMaxN];
vi found_verts;

void DfsSizes(int v, int p) {
  found_verts.PB(v);
  tree_size[v] = 1;
  for (const auto &edge : adj[v]) {
    const int s = edge.st;
    if (is_forbidden[s] || s == p) { continue; }
    DfsSizes(s, v);
    tree_size[v] += tree_size[s];
  }
}

void MakeCentroids(int some_vert) {
  found_verts.clear();
  DfsSizes(some_vert, some_vert);
  const int tot_size = tree_size[some_vert];
  int centr = some_vert;
  
  for (int s : found_verts) {
    if (tree_size[s] * 2 >= tot_size && tree_size[s] < tree_size[centr]) {
      centr = s;
    }
  }
  
  PreprocCentroid(centr);
  is_forbidden[centr] = true;
  
  for (auto &edge : adj[centr]) {
    const int s = edge.st;
    if (!is_forbidden[s]) { MakeCentroids(s); }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  cin >> n >> q >> maxw;
  
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    edges.emplace_back(u, v, SZ(adj[u]), SZ(adj[v]));
    adj[u].emplace_back(v, c);
    adj[v].emplace_back(u, c);
  }
  
  MakeCentroids(1);
  
  ll last = 0;
  
  for (int i = 0; i < q; ++i) {
    int d; ll e;
    cin >> d >> e;
#ifndef NOCHANGE
    d = (d + last) % (n - 1);
    e = (e + last) % maxw;
#endif
    auto [u, v, uidx, vidx] = edges[d];
    const ll cdiff = e - adj[u][uidx].nd;
    adj[u][uidx].nd = adj[v][vidx].nd = e;
    
    int max_layer = min(SZ(centr_pts[v]), SZ(centr_pts[u])) - 1;
    while (centr_pts[u][max_layer].vert != centr_pts[v][max_layer].vert) {
      --max_layer;
    }
    
    for (int layer = max_layer; layer >= 0; --layer) {      
      bool v_up;
      const int centr = centr_pts[u][layer].vert;
      if (u == centr || v == centr) {
        v_up = (v == centr);
      } else {
        v_up = (centr_pts[v][layer].pre < centr_pts[u][layer].pre);
      }
      
      if (v_up) {
        swap(u, v);
      }
      
      const ll old_centr_ans = ReadAns(centr);
      
      auto &mdists = centr_info[centr].max_dists;
      auto &mtree = centr_info[centr].tree;
      const int lv = centr_pts[v][layer].pre;
      const int rv = centr_pts[v][layer].post;
      const int vsidx = centr_pts[v][layer].subtree_idx;
      const auto [l_int, r_int] = centr_info[centr].sub_intvs[vsidx];
      
      mdists.erase(mdists.find(mtree->GetMax(l_int, r_int)));
      mtree->AddIntv(lv, rv, cdiff);
      mdists.insert(mtree->GetMax(l_int, r_int));
      
      const ll centr_ans = ReadAns(centr);
      debug(centr, centr_ans);
      declared_ans.erase(declared_ans.find(old_centr_ans));
      declared_ans.insert(centr_ans);
    }
    
    const ll ans = *declared_ans.rbegin();
    cout << ans << "\n";
    last = ans;
  }
}