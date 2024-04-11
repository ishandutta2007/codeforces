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

const int nax = 1200 * 1007;

vector <int> drz[nax];
int roz[nax], jump[nax], pre[nax], post[nax], fad[nax];
int odl[nax];
int l;

void dfs_roz(int v)
{
	roz[v]=1;
	for (int &i : drz[v])
	{
		fad[i]=v;
		odl[i]=odl[v]+1;
		dfs_roz(i);
		roz[v]+=roz[i];
		if (roz[i]>roz[drz[v][0]])
			swap(i, drz[v][0]);
	}
}

void dfs_pre(int v)
{
	if (!jump[v])
		jump[v]=v;
	l++;
	pre[v]=l;
	if (!drz[v].empty())
		jump[drz[v][0]]=jump[v];
	for (int i : drz[v])
		dfs_pre(i);
	post[v]=l;
}

int lca(int v, int u)
{
	while(jump[v]!=jump[u])
	{
		if (pre[v]<pre[u])
			swap(v, u);
		v=fad[jump[v]];
	}
	return (pre[v]<pre[u] ? v : u);
}

int GetDist(int a, int b)
{
	return odl[a]+odl[b]-2*odl[lca(a, b)];
}

const int MaxN = 2e5 + 100;
const int LogMaxN = 18;

/*int parent[MaxN][LogMaxN];
int depth[MaxN];
vector<int> children[MaxN];

void Dfs(int v) {
  for (int s : children[v]) {
    parent[s][0] = v;
    depth[s] = depth[v] + 1;
    for (int i = 1; i < LogMaxN; ++i) {
      parent[s][i] = parent[parent[s][i - 1]][i - 1];
    }
    Dfs(s);
  }
}

int GetLCA(int u, int v) {
  if (depth[u] < depth[v]) { swap(u, v); }

  for (int b = 0; b < LogMaxN; ++b) {
    if ((depth[u] - depth[v]) & (1 << b))
      u = parent[u][b];
  }

  if (u == v) { return u; }

  for (int b = LogMaxN - 1; b >= 0; --b) {
    const int pu = parent[u][b];
    const int pv = parent[v][b];
    if (pu != pv) { u = pu; v = pv; }
  }
  return parent[u][0];
}

int GetDist(int a, int b) {
  const int L = GetLCA(a, b);
  return depth[a] + depth[b] - depth[L] * 2;
}*/

using Node = PII;

Node Merge(const Node &lhs, const Node &rhs) {
  if (lhs.st == -1 || rhs.st == -1)
    return {-1, -1};
  
  vector<int> alls{lhs.st, lhs.nd, rhs.st, rhs.nd};
  int dists[4][4];
  int a = -1, b = -1, md = -1;
  for (int i = 0; i < 4; ++i)
    for (int j = i + 1; j < 4; ++j) {
      dists[i][j] = dists[j][i] = GetDist(alls[i], alls[j]);
      if (dists[i][j] > md) {
        md = dists[i][j]; a = i; b = j;
      }
    }
  for (int i = 0; i < 4; ++i)
    dists[i][i] = 0;

  for (int i = 0; i < 4; ++i) {
    if (i == a || i == b) { continue; }
    if (dists[a][i] + dists[i][b] != dists[a][b]) { return {-1, -1}; }
  }

  return {alls[a], alls[b]};
}

const int Base = 1 << LogMaxN;

PII tree[Base * 2];


int N;
int values[MaxN];

int GetMex() {
  debug(tree[Base], tree[Base + 1], tree[Base / 2]);
  debug(tree[Base + 2], tree[Base + 3], tree[Base / 2 + 1]);
  int v = 1;
  int cur_size = Base;
  int ans = 0;
  while (tree[v].st == -1) { v *= 2; cur_size /= 2; }

  Node node = tree[v];
  ++v;
  ans = cur_size;
  while (v < Base * 2) {
    const Node cand = Merge(node, tree[v]);
    if (cand.st == -1) { v *= 2; cur_size /= 2; continue; }
    node = cand;
    ++v;
    ans += cur_size;
  }
  return ans;
}

void PutVal(int p, int x) {
  p += Base;
  tree[p] = {x, x};
  p /= 2;
  while (p) {
    tree[p] = Merge(tree[p * 2], tree[p * 2 + 1]);
    p /= 2;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> values[i];
    tree[values[i] + Base] = {i, i};
  }

  for (int i = 1; i < N; ++i) {
    int v;
    cin >> v;
    drz[v - 1].PB(i);
  }

  dfs_roz(0);
	dfs_pre(0);
  debug(GetDist(0, 1));

  for (int i = N; i < Base; ++i)
    tree[i + Base] = PII{-1, -1};
  for (int i = Base - 1; i > 0; --i)
    tree[i] = Merge(tree[i * 2], tree[i * 2 + 1]);


  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int t;
    cin >> t;

    if (t == 2) {
      cout << GetMex() << "\n";
    } else {
      int u, v;
      cin >> u >> v;
      --u; --v;
      swap(values[u], values[v]);
      PutVal(values[u], u);
      PutVal(values[v], v);
    }
  }
}