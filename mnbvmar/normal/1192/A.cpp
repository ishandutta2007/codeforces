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

const int kMaxN = 2e5;
const int kMaxVert = 5e5;
const int M = 1.02e9;

const int dr[] = {-1, -1, -1, 0, 1, 1,  1,  0};
const int dc[] = {-1,  0,  1, 1, 1, 0, -1, -1};
map<int, vector<tuple<int, int, int>>> intvs;
const int kNumDirs = 8;

vector<pii> cells;
map<pii, int> cell_mapping;
bool vis[kMaxN];
vi adj[kMaxVert];

int fu_parent[kMaxVert];
//~ vi fu_elems[kMaxVert];

int n;
int outside_vert;
set<int> avail_verts;
set<int> quarantine_verts;
vector<bool> is_free;

int FuFind(int v) {
  if (v == fu_parent[v]) { return v; }
  return fu_parent[v] = FuFind(fu_parent[v]);
}

void FuUnion(int a, int b) {
  a = FuFind(a); b = FuFind(b);
  if (a == b) { return; }
  fu_parent[a] = b;
  //~ if (SZ(fu_elems[a]) > SZ(fu_elems[b])) { swap(a, b); }
  
  //~ for (int x : {a, b}) {
    //~ if (x == FuFind(outside_vert)) {
      //~ const int y = x ^ a ^ b;
      //~ for (int s : fu_elems[y]) {
        //~ avail_verts.insert(s);
      //~ }
    //~ }
  //~ }
  
  //~ fu_parent[a] = b;
  //~ for (int x : fu_elems[a]) {
    //~ fu_elems[b].PB(x);
  //~ }
  //~ fu_elems[a].clear();
}

int GetByID(int r, int c) {
  auto &I = intvs[c];
  assert(!I.empty());
  auto iter = prev(upper_bound(ALL(I),
      tuple<int,int,int>(r, M + 100, -1)));
  return get<2>(*iter);
}

bool MakesDisconnected(int v) {
  assert(v < n);
  bool is_adj[10];
  memset(is_adj, 0, sizeof(is_adj));
  
  for (int i = 0; i < 8; ++i) {
    const int nr = cells[v].st + dr[i];
    const int nc = cells[v].nd + dc[i];
    //~ debug(v, nr, nc);
    const pii np{nr, nc};
    auto iter = cell_mapping.find(np);
    if (iter == cell_mapping.end()) { continue; }
    const int s = iter->nd;
    is_adj[i] = !is_free[s];
  }
  
  set<int> comp_ids;
  for (int i = 0; i < 8; ++i) {
    const int j = (i + 1) % 8;
    if (is_adj[i] && !is_adj[j]) {
      if (j % 2 == 0 && is_adj[j + 1]) { continue; }
      debug(v, i, j);
      const int nr = cells[v].st + dr[j];
      const int nc = cells[v].nd + dc[j];
      const int cid = FuFind(GetByID(nr, nc));
      if (comp_ids.count(cid)) { return true; }
      comp_ids.insert(cid);
    }
  }
  return false;
}


inline void AddEdge(int u, int v) {
  debug(u, v);
  adj[u].PB(v); adj[v].PB(u);
}

void Dfs(int v) {
  vis[v] = true;
  for (int i = 0; i < kNumDirs; ++i) {
    const int nr = cells[v].st + dr[i];
    const int nc = cells[v].nd + dc[i];
    const pii np{nr, nc};
    auto iter = cell_mapping.find(np);
    if (iter != cell_mapping.end()) {
      const int s = iter->nd;
      if (!vis[s]) { Dfs(s); }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  int tidx;
  cin >> n >> tidx;
  cells.resize(n);
  for (auto &[r, c] : cells) { cin >> r >> c; }
  for (int i = 0; i < n; ++i) {
    cell_mapping[cells[i]] = i;
  }
  
  Dfs(0);
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  
  int min_c = M, max_c = -M;
  map<int, vector<pii>> cell_cols;
  for (int i = 0; i < n; ++i) {
    mini(min_c, cells[i].nd);
    maxi(max_c, cells[i].nd);
    cell_cols[cells[i].nd].emplace_back(cells[i].st, i);
  }
  
  assert(max_c - min_c <= n);
  
  int cur_id = n;
  
  for (int col = min_c; col <= max_c; ++col) {
    vector<pii> rows = cell_cols[col];
    assert(!rows.empty());
    sort(ALL(rows));
    
    int last_r = -M;
    
    for (auto &&[r, idx] : rows) {
      if (last_r < r - 1) {
        intvs[col].emplace_back(last_r + 1, r, cur_id++);
      }
      intvs[col].emplace_back(r, r + 1, idx);
      last_r = r;
    }
    intvs[col].emplace_back(last_r + 1, M, cur_id++);
  }
  
  intvs[min_c - 1].emplace_back(-M, M, cur_id++);
  intvs[max_c + 1].emplace_back(-M, M, cur_id++);
  const int nverts = cur_id;
  
  for (int col = min_c; col <= max_c; ++col) {
    const auto &I = intvs[col];
    const int sz = SZ(I);
    for (int i = 1; i < sz; ++i) {
      AddEdge(get<2>(I[i - 1]), get<2>(I[i]));
    }
  }
  
  for (int col = min_c; col <= max_c + 1; ++col) {
    int aptr = 0, bptr = 0;
    const auto &A = intvs[col - 1];
    const auto &B = intvs[col];
    while (aptr < SZ(A) && bptr < SZ(B)) {
      const auto [al, ar, aidx] = A[aptr];
      const auto [bl, br, bidx] = B[bptr];
      if (ar <= bl) { ++aptr; continue; }
      if (br <= al) { ++bptr; continue; }
      AddEdge(aidx, bidx);
      if (ar < br) { ++aptr; } else { ++bptr; }
    }
  }
  
  debug(nverts);
  outside_vert = nverts - 1;
  iota(fu_parent, fu_parent + nverts, 0);
  //~ for (int i = 0; i < nverts; ++i) {
    //~ fu_elems[i].PB(i);
  //~ }
  for (int i = n; i < nverts; ++i) {
    for (int j : adj[i]) {
      if (j > i) {
        FuUnion(i, j);
      }
    }
  }
  
  vector<bool> is_deleted(nverts);
  avail_verts.insert(outside_vert);
  
  is_free.resize(nverts);
  for (int i = n; i < nverts; ++i) {
    is_free[i] = true;
  }
  
  vi answer;
  while (SZ(answer) < n) {
    if (avail_verts.empty()) {
      debug(answer);
      debug(vi(ALL(quarantine_verts)));
    }
    assert(!avail_verts.empty());
    const int v = *avail_verts.rbegin();
    avail_verts.erase(v);
    debug(v);
    
    if (v < n && MakesDisconnected(v)) {
      quarantine_verts.insert(v);
      continue;
    } else {
      is_free[v] = is_deleted[v] = true;
      if (v < n) { answer.PB(v); }
      for (int s : adj[v]) {
        if (!is_deleted[s]) { avail_verts.insert(s); }
        quarantine_verts.erase(s);
        if (is_free[s]) {
          FuUnion(v, s);
        }
      }
      
      if (v < n) {
        for (int ddr : {-1, 1}) {
          for (int ddc : {-1, 1}) {
            bool any_free = false;
            const int nrow = GetByID(cells[v].st + ddr, cells[v].nd);
            any_free |= is_free[nrow];
            const int ncol = GetByID(cells[v].st, cells[v].nd + ddc);
            any_free |= is_free[ncol];
            if (!any_free) { continue; }
            
            pii np{cells[v].st + ddr, cells[v].nd + ddc};
            auto iter = cell_mapping.find(np);
            if (iter != cell_mapping.end()) {
              const int s = iter->nd;
              if (!is_deleted[s]) {
                avail_verts.insert(s); quarantine_verts.erase(s);
              }
            }
          }
        }
      }
    }
  }
  
  reverse(ALL(answer));
  cout << "YES\n";
  for (int x : answer) { cout << x + 1 << "\n"; }
}