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

struct Testcase {
  int N;
  vector<VI> adj;
  string colors;

  int Check(const string &s) {
    bool fail = false;
    bool ok = false;
    for (int v = 0; v < N - 1; ++v) {
      int nn = 0;
      for (int t : adj[v]) { nn += s[t] == s[v]; }
      if (nn >= 2) {
        if (s[v] == 'W') { ok = true; }
        if (s[v] == 'B') { fail = true; }
      }
    }
    debug("Check", s, ok, fail);
    if (ok) { return 1; }
    if (fail) { return -1; }
    return 0;
  }

  bool Brute() {
    debug("Brute");
    string cur_cols = colors;

    function<bool(bool)> Bt = [&](bool who) {
      const int vvv = Check(cur_cols);
      if (vvv) { return vvv == 1; }
      bool had_any = false;
      for (int i = 0; i < N; ++i) {
        if (cur_cols[i] == 'N') {
          cur_cols[i] = who ? 'W' : 'B';
          const bool ans = Bt(!who);
          cur_cols[i] = 'N';
          if (who == ans) { debug(cur_cols, who, ans, i); return ans; }
          had_any = true;
        }
      }

      if (had_any) { return !who; }
      return false;
    };

    return Bt(true);
  }

  bool Run() {
    cin >> N;
    adj.resize(N);

    for (int i = 0; i < N - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      adj[u].PB(v);
      adj[v].PB(u);
    }
    cin >> colors;

    vector<int> whites;
    VI threes;

    for (int i = 0; i < N; ++i) {
      if (SZ(adj[i]) >= 4) { return true; }

      if (SZ(adj[i]) == 3) {
        threes.PB(i);
        vector<int> degs;
        for (int v : adj[i]) { degs.PB(SZ(adj[v])); }
        sort(ALL(degs));
        if (degs[1] >= 2) { return true; }
      }

      if (colors[i] == 'W') {
        if (SZ(adj[i]) >= 3) { return true; }
        whites.PB(i);
        if (SZ(adj[i]) == 2) {
          vector<int> degs;
          for (int v : adj[i]) {
            degs.PB(SZ(adj[v]));
          }
          sort(ALL(degs));
          if (degs[0] >= 1 && degs[1] >= 2) { return true; }
        }
        for (int v : adj[i]) {
          if (SZ(adj[v]) >= 3) { return true; }
        }
      }
    }

    /*if (N == 7) {
      int p2 = -1;
      for (int i = 0; i < N; ++i) {
        if (SZ(adj[i]) == 2) { p2 = i; }
      }

      if (p2 != -1) {
        bool fail = false;
        for (int v : adj[p2]) {
          if (SZ(adj[v]) != 3) { fail = true; break; }
        }
        if (!fail) { return true; }
      }
    }*/
    
    if (N <= 7) {
      return Brute();
    }
    
    assert(SZ(whites) <= 2);

    if (SZ(whites) == 2) {
      return N % 2 == 1;
    } else if (SZ(threes) == 1) {
      return SZ(whites) == 1 && N % 2 == 0;
    } else if (SZ(threes) == 2) {
      return N % 2 == 1;
    } else {
      return false;
    }
    assert(false);
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    const bool ans = Testcase().Run();
    cout << (ans ? "White\n" : "Draw\n");
  }
}