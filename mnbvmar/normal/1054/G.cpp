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

constexpr int MaxN = 2048;

struct Testcase {
  vector<bitset<MaxN>> comm_belongs;
  vector<vector<int>> adj;
  vector<vector<int>> num_bad;
  vector<int> comm_size;
  vector<string> input;
  int N, M;
  vector<int> degree;

  bool CheckTree() {
    for (int i = 0; i < M; ++i) {
      string &patt = input[i];
      if (count(ALL(patt), '1') == 0) { continue; }
      int idx = 0;
      while (patt[idx] == '0') { ++idx; }

      vector<bool> visited(N, false);

      function<void(int)> Dfs = [&](int v) {
        visited[v] = true;
        for (int s : adj[v]) {
          if (patt[s] == '0') { continue; }
          if (!visited[s]) {Dfs(s);}
        }
      };

      Dfs(idx);

      for (int j = 0; j < N; ++j)
        if (patt[j] == '1' && !visited[j])
          return false;
    }
    return true;
  }

  void Run() {
    debug("test");
    cin >> N >> M;
    adj.resize(N);
    degree.resize(N);
    comm_size.resize(M);

    input.resize(M);
    int idx = 0;
    for (auto &in : input) {
      cin >> in;
      comm_size[idx] = count(ALL(in), '1');
      if (comm_size[idx] == 1) { fill(ALL(in), '0'); comm_size[idx] = 0; }
      ++idx;
    }

    comm_belongs.resize(N);

    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        if (input[i][j] == '1') {
          comm_belongs[j][i] = true;
          ++degree[j];
        }

    num_bad.resize(N, vector<int>(N));

    vector<bool> used_up(N);
    queue<PII> Q;

    auto FreeComm = [&](int comm_idx) {
      debug("Free", comm_idx);
      int pos = 0;
      while (used_up[pos] || input[comm_idx][pos] == '0') { ++pos; }
      for (int other = 0; other < N; ++other) {
        if (pos == other) { continue; }
        if (used_up[other]) { continue; }
        --num_bad[pos][other];
        if (num_bad[pos][other] == 0)
          Q.push(make_pair(pos, other));
      }
    };

    for (int a = 0; a < N; ++a) {
      for (int b = a + 1; b < N; ++b) {
        const auto &bs = comm_belongs[a] & comm_belongs[b];
        const int bs_count = bs.count();
        num_bad[a][b] = degree[a] - bs_count;
        num_bad[b][a] = degree[b] - bs_count;
        debug(a, b, bs_count, num_bad[a][b], num_bad[b][a]);
      }
    }

    for (int a = 0; a < N; ++a)
      for (int b = 0; b < N; ++b)
        if (a != b && !num_bad[a][b])
          Q.push(make_pair(a, b));

    int num_iters = 0;
    while (!Q.empty()) {
      const auto [leaf, parent] = Q.front();
      Q.pop();
      if (used_up[leaf] || used_up[parent]) { continue; }
      adj[leaf].PB(parent);
      adj[parent].PB(leaf);
      debug(leaf, parent);
      used_up[leaf] = true;
      ++num_iters;

      for (int comm_idx = 0; comm_idx < M; ++comm_idx) {
        if (input[comm_idx][leaf] == '0') { continue; }
        --comm_size[comm_idx];
        if (comm_size[comm_idx] == 1)
          FreeComm(comm_idx);
      }
    }

    if (num_iters != N - 1 || !CheckTree()) {
      cout << "NO\n"; return;
    }

    cout << "YES\n";
    for (int i = 0; i < N; ++i)
      for (int s : adj[i])
        if (s > i)
          cout << i+1 << " " << s+1 << "\n";
  }
};


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int T;
  cin >> T;
  for (int i = 0; i < T; ++i)
    Testcase().Run();
}