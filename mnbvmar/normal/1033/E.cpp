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

#ifdef LOCAL
int _N;
bool _graph[800][800];
int _num_asked = 0;
bool _is_bipartite;
#endif

int GetN() {
  int N;
  cin >> N;
#ifdef LOCAL
  _N = N;
  cin >> _is_bipartite;
  for (int i = 1; i <= N; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < N; ++j)
      _graph[i][j + 1] = s[j] == '1';
  }
#endif
  return N;
}

map<vector<int>, int> small_memo;

int Ask(const vector<int> &verts) {
  if (verts.empty()) { return 0; }
  if (verts.size() == 1) { return 0; }
  if (verts.size() < 15) {
    if (small_memo.count(verts))
      return small_memo[verts];
  }
#ifdef LOCAL
  ++_num_asked;
  int ans = 0;
  for (int i = 0; i < SZ(verts); ++i)
    for (int j = i + 1; j < SZ(verts); ++j)
      ans += _graph[verts[i]][verts[j]];
  debug("ask", verts, ans);
  if (verts.size() < 15)
    small_memo[verts] = ans;
  return ans;
#else
  cout << "? " << SZ(verts) << endl;
  for (int s : verts) cout << s << " ";
  cout << endl;
  int res;
  cin >> res;
  if (verts.size() < 15)
    small_memo[verts] = res;
  return res;
#endif
}

int Ask(const vector<bool> &is_vert) {
  vector<int> verts;
  for (int i = 0; i < SZ(is_vert); ++i)
    if (is_vert[i])
      verts.PB(i + 1);
  return Ask(verts);
}

void Answer(bool answer, const vector<int> &proof) {
#ifdef LOCAL
  debug("answer", answer, proof);
  assert(answer == _is_bipartite);
  debug(_num_asked);
  exit(0);
#else
  cout << (answer ? "Y " : "N ") << SZ(proof) << endl;;
  for (int s : proof) cout << s << " ";
  cout << endl;
  exit(0);
#endif
}


int N;

vector<bool> to_discover;
queue<int> knowns;

vector<int> DiscoverVert(int v) {
  vector<int> remaining;
  for (int i = 0; i < N; ++i)
    if (to_discover[i])
      remaining.push_back(i + 1);

  vector<int> neigh;

  auto AnyVertTo = [&](vector<int> X) {
    const int num_inside = Ask(X);
    X.PB(v);
    const int num_total = Ask(X);
    return num_total > num_inside;
  };

  function<void(vector<int>)> bt = [&](vector<int> rem) {
    debug(v, rem);
    if (SZ(rem) == 0) { return; }
    if (SZ(rem) == 1) {
      neigh.PB(rem[0]);
      return;
    }

    const int m = SZ(rem) / 2;
    const vector<int> L = vector<int>(rem.begin(), rem.begin() + m);
    const vector<int> R = vector<int>(rem.begin() + m, rem.end());
    if (AnyVertTo(L))
      bt(L);
    if (AnyVertTo(R))
      bt(R);
  };

  if (AnyVertTo(remaining))
    bt(remaining);

  for (int s : neigh)
    to_discover[s - 1] = false;
  return neigh;
}

int a, b;
int parent[1000];
vector<int> children[1000];
bool color[1000];

void Dfs(int v) {
  for (int s : children[v]) {
    color[s] = !color[v];
    Dfs(s);
  }
}

PII FindEdge(vector<int> v) {
  assert(SZ(v) >= 2);
  while (SZ(v) > 2) {
    int x = v.back();
    v.pop_back();
    if (!Ask(v))
      v.insert(v.begin(), x);
  }
  return {v[0], v[1]};
}


VI PathToRoot(int v) {
  VI path{v};
  while (path.back() != 0)
    path.PB(parent[path.back()]);
  return path;
}

int32_t main() {
  /* ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);*/

  N = GetN();
  if (N == 1)
    Answer(true, {1});

  to_discover.resize(N, true);
  to_discover[0] = false;
  knowns.push(1);

  while (!knowns.empty()) {
    int v = knowns.front();
    knowns.pop();

    auto E = DiscoverVert(v);
    for (int s : E) {
      debug(v, s);
      parent[s] = v;
      children[v].PB(s);
      knowns.push(s);
    }
  }

  Dfs(1);

  vector<int> L, R;
  for (int i = 1; i <= N; ++i)
    if (color[i])
      R.PB(i);
    else
      L.PB(i);

  debug(L, R);

  const int edges_left = Ask(L);
  const int edges_right = Ask(R);

  if (!edges_left && !edges_right)
    Answer(true, L);

  PII edge;

  if (edges_left)
    edge = FindEdge(L);
  else
    edge = FindEdge(R);

  debug(edge);

  VI path_a = PathToRoot(edge.st);
  VI path_b = PathToRoot(edge.nd);

  debug(path_a, path_b);

  int last_rem = -1;
  while (SZ(path_a) && SZ(path_b) && path_a.back() == path_b.back()) {
    last_rem = path_a.back();
    path_a.pop_back();
    path_b.pop_back();
  }

  debug(path_a, path_b, last_rem);
  reverse(ALL(path_b));

  vector<int> total = path_a;
  total.PB(last_rem);
  for (int x : path_b) { total.PB(x); }
  Answer(false, total);
}