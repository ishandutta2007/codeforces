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

const vector<VI> kShifts = {
  {0, 1, 4, 3}, {0, 3, 4, 1},
  {1, 2, 5, 4}, {1, 4, 5, 2},
  {3, 4, 7, 6}, {3, 6, 7, 4},
  {4, 5, 8, 7}, {4, 7, 8, 5},
};

VI Apply(VI perm, const VI &shift) {
  vector<int> elems(SZ(shift));
  for (int i = 0; i < SZ(shift); ++i)
    elems[i] = perm[shift[i]];

  for (int i = 0; i < SZ(shift); ++i)
    perm[shift[(i + 1) % SZ(shift)]] = elems[i];

  return perm;
}

int GetIndex(const vector<int> &perm) {
  vector<bool> has_it(9);
  int coef = 362880;
  int idx = 0;

  for (int i = 0; i < SZ(perm); ++i) {
    coef /= SZ(perm) - i;
    const int v = perm[i];
    int num_lower = 0;
    for (int j = 0; j < v; ++j)
      num_lower += !has_it[j];
    idx += coef * num_lower;
    has_it[v] = true;
  }

  // debug(perm, has_it, idx, coef);

  return idx;
}

const int kNumPerms = 5e5;

bool visited[kNumPerms];
VI op_done[kNumPerms];
int cur_dist[kNumPerms];
int parent[kNumPerms];

void Preproc() {
  queue<VI> Q;

  VI start(9);
  iota(ALL(start), 0);
  visited[GetIndex(start)] = true;
  Q.push(start);

  int num_visited = 0;
  int max_dist = 0;

  while (!Q.empty()) {
    auto V = Q.front(); Q.pop();
    ++num_visited;
    const int idx = GetIndex(V);
    const int dist = cur_dist[idx];
    maxi(max_dist, dist);
    // debug(V);

    for (auto &shift : kShifts) {
      const VI next_v = Apply(V, shift);
      const int next_idx = GetIndex(next_v);
      if (!visited[next_idx]) {
        visited[next_idx] = true;
        op_done[next_idx] = shift;
        cur_dist[next_idx] = dist + 1;
        parent[next_idx] = idx;
        Q.push(next_v);
      }
    }
  }
  debug(num_visited, max_dist);

}

const int MaxDim = 24;
int datax[MaxDim][MaxDim];
int data_copy[MaxDim][MaxDim];
int N, M;

vector<VI> cycles;

void SwapTwo(int r1, int c1, int r2, int c2) {
  debug("SwapTwo", r1, c1, r2, c2);
  assert(abs(r1 - r2) <= 2 && abs(c1 - c2) <= 2);

  const int r0 = min(N - 3, min(r1, r2));
  const int c0 = min(M - 3, min(c1, c2));

  /* vector<int> order(9);
  iota(ALL(order), 0);
  sort(ALL(order), [&](int lhs, int rhs) {
        int rl = lhs / 3, cr = lhs % 3;
        int rr = rhs / 3, cr = rhs % 3;
        return datax[r0+rl][c0+cr] < data[r0+rr][c0+cr];
      }); */

  const int swap1 = (r1-r0)*3+(c1-c0);
  const int swap2 = (r2-r0)*3+(c2-c0);

  vector<int> order(9);
  iota(ALL(order), 0);
  swap(order[swap1], order[swap2]);
  int cur_idx = GetIndex(order);

  vector<VI> ops;

  while (cur_idx != 0) {
    const VI cycle = op_done[cur_idx];
    ops.PB(cycle);
    cur_idx = parent[cur_idx];
  }
  
  reverse(ALL(ops));
  for (auto &cycle : ops) {
    VI description;
    for (int v : cycle)
      description.push_back(datax[r0 + v / 3][c0 + v % 3]);

    const int S = SZ(cycle);
    for (int i = 0; i < S; ++i) {
      const int j = (i + S - 1) % S;
      const int v = cycle[i];
      datax[r0+v/3][c0+v%3] = description[j];
    }

#ifdef LOCAL
    debug(description);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j)
        cerr << datax[i][j] << "\t";
      cerr << "\n";
    }
#endif

    cycles.push_back(description);
  }

  // swap(datax[r1][c1], datax[r2][c2]);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  Preproc();

  cin >> N >> M;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) {
      cin >> datax[i][j];
      data_copy[i][j] = datax[i][j];
    }


  for (int idx = 1; idx <= N * M; ++idx) {
    int r = -1, c = -1;
    const int needed_r = (idx - 1) / M;
    const int needed_c = (idx - 1) % M;

    debug(idx, r, c, needed_r, needed_c);

    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        if (datax[i][j] == idx) {
          r = i;
          c = j;
        }

    assert(r != -1);
    assert(c != -1);

    auto GetCloser = [&](int from, int to) {
      if (from < to)
        return min(to, from + 2);
      else
        return max(to, from - 2);
    };

    while(tie(r, c) != tie(needed_r, needed_c)) {
      int next_r = GetCloser(r, needed_r);
      int next_c = GetCloser(c, needed_c);
      while (make_pair(next_r, next_c) < make_pair(needed_r, needed_c))
        ++next_r;
      SwapTwo(r, c, next_r, next_c);
      r = next_r;
      c = next_c;
    }
#ifdef LOCAL
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j)
        cerr << datax[i][j] << "\t";
      cerr << "\n";
    }
#endif

  }

  vector<PII> cur_loc(N * M + 1);
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      cur_loc[data_copy[i][j]] = MP(i, j);

  int total_len = 0;

  cout << SZ(cycles) << "\n";
  for (auto &V : cycles) {
    cout << SZ(V);
    for (int v : V) cout << " " << v;
    cout << "\n";

    vector<PII> C;
    for (int v : V)
      C.PB(cur_loc[v]);

    vector<tuple<int, int>> new_locs;

    for (int i = 0; i < SZ(C); ++i) {
      const int j = V[(i + 1) % SZ(C)];
      data_copy[cur_loc[j].st][cur_loc[j].nd] = V[i];
      new_locs.emplace_back(cur_loc[j].st, cur_loc[j].nd);
    }

    for (auto &[r, c] : new_locs)
      cur_loc[data_copy[r][c]] = MP(r, c);

#ifdef LOCAL
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j)
        cerr << data_copy[i][j] << "\t";
      cerr << "\n";
    }
#endif

    total_len += SZ(V);
  }

  cout << flush;

  debug(total_len);
  assert(total_len < 1e5);

#ifdef LOCALX
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j)
        cout << data_copy[i][j] << "\t";
      cout << "\n";
    }
    cout << flush;
#endif

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      assert(data_copy[i][j] == i * M + j + 1);
}