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

struct SA {
  vector<map<char, int>> edges;
  VI link, length;
  int last;

  SA(string s) : edges(1), link{-1}, length(1), last(0) {
    REP (i, SZ(s)) {
      edges.emplace_back();
      length.PB(i + 1);
      link.PB(0);
      int r = SZ(edges) - 1, p = last;
      while (p >= 0 && edges[p].find(s[i]) == edges[p].end()) {
        edges[p][s[i]] = r;
        p = link[p];
      }
      if (p != -1) {
        int q = edges[p][s[i]];
        if (length[p] + 1 == length[q]) {
          link[r] = q;
        } else {
          edges.PB(edges[q]);
          length.PB(length[p] + 1);
          link.PB(link[q]);
          int qq = SZ(edges) - 1;
          link[q] = qq; link[r] = qq;
          while (p >= 0 && edges[p][s[i]] == q) {
            edges[p][s[i]] = qq;
            p = link[p];
          }
        }
      }
      last = r;
    }
  }
};

const int Mod = 1e9 + 7;
const int MaxN = 3005;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  string s;
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) { char ch; cin >> ch; s += ch; }
  SA sa(s);

  const int size = SZ(sa.edges);
  vector<int> first_occur(size, 0);
  vector<bool> visited(size);
  function<void(int)> Dfs = [&](int v) {
    visited[v] = true;
    for (auto &edge : sa.edges[v]) {
      if (!visited[edge.nd]) { Dfs(edge.nd); }
      maxi(first_occur[v], first_occur[edge.nd] + 1);
    }
  };

  Dfs(0);
  for (int i = 0; i < size; ++i) {
    first_occur[i] = N - first_occur[i];
  }
  debug(first_occur);

  vector<LL> answers(N);

  for (int L = 0; L < N; ++L) {
    int pos = 0;
    LL num_found[4] = {1, 0, 0, 0};

    for (int R = L; R < N; ++R) {
      pos = sa.edges[pos][s[R]];
      LL n0 = 0;

      if (R >= 3) {
        const string my = s.substr(R - 3, 4);
        if (my != "0011" && my != "0101" && my != "1110" && my != "1111") {
          n0 += num_found[3];
        }
      }

      n0 += num_found[0] + num_found[1] + num_found[2];
      num_found[3] = num_found[2];
      num_found[2] = num_found[1];
      num_found[1] = num_found[0];
      num_found[0] = n0 % Mod;

      debug(L, R, pos, first_occur[pos], num_found[0], num_found[1], num_found[2], num_found[3]);
      if (first_occur[pos] == R + 1) {
        debug(L, R);
        answers[R] = (answers[R] + num_found[0]) % Mod;
      }
    }
  }

  for (int i = 1; i < N; ++i) {
    answers[i] = (answers[i - 1] + answers[i]) % Mod;
  }

  for (LL v : answers) { cout << v << "\n"; }
}