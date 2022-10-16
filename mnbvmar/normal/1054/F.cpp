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

int N;
vector<PII> points;
map<int, set<int>> verts, horizs;
map<int, vector<int>> ends_vert, ends_horiz;

const int MaxS = 4000;

vector<pair<PII, PII>> vert_list, horiz_list;
set<pair<PII, PII>> vert_bad, horiz_bad;
int A, B;
vector<int> adj[MaxS];
int match_left[MaxS], match_right[MaxS];
bool visited[MaxS];
bool indep_left[MaxS], indep_right[MaxS];

bool Between(int a, int x, int b) {
  if (a > b) { swap(a, b); }
  return a < x && x < b;
}

bool DfsMatch(int v) {
  if (visited[v]) { return false; }
  visited[v] = true;

  for (int s : adj[v]) {
    if (match_right[s] == -1 || DfsMatch(match_right[s])) {
      match_right[s] = v;
      match_left[v] = s;
      return true;
    }
  }
  return false;
}

void Match() {
  fill_n(match_left, A, -1);
  fill_n(match_right, B, -1);

  bool improved;
  do {
    improved = false;

    fill_n(visited, A, false);
    for (int i = 0; i < A; ++i)
      if (!visited[i] && match_left[i] == -1 && DfsMatch(i))
        improved = true;

  } while (improved);
}


void Independent() {
  fill_n(visited, A, false);
  for (int i = 0; i < A; ++i)
    if (!visited[i] && match_left[i] == -1)
      assert(!DfsMatch(i));

  for (int i = 0; i < A; ++i) {
    if (match_left[i] == -1) { continue; }
    if (visited[i])
      indep_right[match_left[i]] = true;
    else
      indep_left[i] = true;
  }
}

void OutVec(vector<int> v) {
  assert(SZ(v) % 4 == 0);
  cout << SZ(v) / 4 << "\n";
  int ptr = 0;
  for (int t : v) {
    cout << t << " ";
    ++ptr;
    if (ptr % 4 == 0) { cout << "\n"; }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  points.resize(N);
  for (auto &&[x, y] : points) {
    cin >> x >> y;
    verts[x].insert(y);
    horizs[y].insert(x);
  }

  for (auto &&[x, s] : verts) {
    vector<int> lst(ALL(s));
    ends_vert[x].PB(lst[0]);
    ends_vert[x].PB(lst.back());
    for (int i = 1; i < SZ(lst); ++i)
      vert_list.emplace_back(PII(x, lst[i - 1]), PII(x, lst[i]));
  }
  for (auto &&[y, s] : horizs) {
    vector<int> lst(ALL(s));
    ends_horiz[y].PB(lst[0]);
    ends_horiz[y].PB(lst.back());
    for (int i = 1; i < SZ(lst); ++i)
      horiz_list.emplace_back(PII(lst[i - 1], y), PII(lst[i], y));
  }

  A = SZ(vert_list);
  B = SZ(horiz_list);
  for (int i = 0; i < A; ++i)
    for (int j = 0; j < B; ++j) {
      auto &V = vert_list[i];
      auto &H = horiz_list[j];
      if (Between(H.st.st, V.st.st, H.nd.st) && Between(V.st.nd, H.st.nd, V.nd.nd))
        adj[i].PB(j);
    }

  Match();
  Independent();

  for (int i = 0; i < A; ++i)
    if (indep_left[i]) {
      auto &V = vert_list[i];
      ends_vert[V.st.st].PB(V.st.nd);
      ends_vert[V.st.st].PB(V.nd.nd);
    }
  for (int i = 0; i < B; ++i)
    if (indep_right[i]) {
      auto &H = horiz_list[i];
      ends_horiz[H.st.nd].PB(H.st.st);
      ends_horiz[H.st.nd].PB(H.nd.st);
    }

  vector<int> answer_vert, answer_horiz;
  for (auto [x, v] : ends_vert) {
    sort(ALL(v));
    assert(SZ(v) % 2 == 0);
    for (int y : v) {
      answer_vert.PB(x);
      answer_vert.PB(y);
    }
  }
  for (auto [y, v] : ends_horiz) {
    sort(ALL(v));
    assert(SZ(v) % 2 == 0);
    for (int x : v) {
      answer_horiz.PB(x);
      answer_horiz.PB(y);
    }
  }
  OutVec(answer_horiz);
  OutVec(answer_vert);
}