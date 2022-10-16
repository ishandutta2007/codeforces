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

struct Test {
  int N;
  vector<VI> adj;
  vector<bool> is_mine, is_his;

  VI ReadVec() {
    int k;
    cin >> k;
    VI ans(k);
    for (int &x : ans) { cin >> x; }
    return ans;
  }

  int Dfs(int v, int p) {
    if (is_mine[v]) { return v; }
    for (int s : adj[v]) {
      if (s == p) { continue; }
      const int a = Dfs(s, v);
      if (a)
        return a;
    }
    return 0;
  }

  void Run() {
    cin >> N;
    adj.resize(N + 1);
    is_mine.resize(N + 1);
    is_his.resize(N + 1);
    for (int i = 0; i < N - 1; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].PB(v);
      adj[v].PB(u);
    }

    vector<int> my_nodes = ReadVec();
    vector<int> his_nodes = ReadVec();

    for (int v : my_nodes)
      is_mine[v] = true;
    for (int v : his_nodes)
      is_his[v] = true;

    cout << "B " << his_nodes[0] << endl;
    int my_corr;
    cin >> my_corr;

    const int my_close = Dfs(my_corr, my_corr);
    assert(my_close);
    cout << "A " << my_close << endl;
    int his_close;
    cin >> his_close;

    if (is_his[his_close]) {
      cout << "C " << my_close << endl;
    } else {
      cout << "C -1" << endl;
    }
  }
};

int32_t main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i)
    Test().Run();
}