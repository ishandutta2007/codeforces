#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
// #define int LL
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
  vector<pair<PII, int>> x;
  VI suf; // <- numery kolejnych sufiksow w porzadku leksykograficznym
  VI rank; // <- odwrotnosc tablicy sufiksowej (suf)
  VI lcp; // lcp[i] == lcp(suf[i-1],suf[i])
  string z;
  int n;
  SA(string z_, int n_) : z(z_), n(n_) {
    z[n] = -1; // straznik zaklada ze -1 nie wystepuje w z
    //ostroznie coby nic nie nadpisac    
    suf.resize(n); rank.resize(n); x.resize(n);
    R(i, n) { x[i] = {{z[i], 0}, i}; }
    mapuj();
    int krok = 1;
    while (krok < n) {
      R (i, n) { x[i] = {{rank[i], i + krok < n ? rank[i + krok] : -1}, i}; }
      mapuj();
      krok *= 2;
    }
    R(i, n) { suf[rank[i]] = i; }
    
    //LCP - opcjonalnie
    lcp.resize(n);
    int k = 0;
    R(i, n) {
      int ak = rank[i];
      if(ak) { while (z[suf[ak] + k] == z[suf[ak - 1] + k]) k++; }
      lcp[rank[i]] = k;
      if(k) { k--; }
    }
    //koniec LCP
  };
  void mapuj() {
    sort(ALL(x));
    int id = 0;
    R (i, n) {
      if (i && x[i - 1].st != x[i].st) id++;
      rank[x[i].nd] = id;
    }
  }
};
/*
                              // 13 1 2 1 1 2 1 2 1 1 2 1 1 2
int z[(int)1e6], n;           //   -> 10 7 2 11 8 5 0 3 12 9 6 1 4
int32_t main(){               //   -> 3 4 1 2 5 6 3 0 1 4 5 2
  scanf("%lld",&n);
  R(i,n)scanf("%lld",&z[i]);
  SA sa(z,n);
  R(i,n)printf("%lld ",sa.suf[i]);
  puts("");
  for(int i = 1; i < n; i++) printf("%lld ",sa.lcp[i]);
  puts("");
} */

int N;
string s;

const int MaxCh = 26;
const int MaxN = 5e5 + 100;

bool is_of_length[MaxN];
bool next_is_of_length[MaxN];
int total_infos = 0;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> s;
  SA sa(s, N);
  fill_n(is_of_length, N, true);
  int length = 1;

  debug(sa.suf, sa.lcp);

  while (count(is_of_length, is_of_length + N, true)) {
#ifdef LOCAL
    debug(length);
    for (int i = 0; i < N; ++i)
      cerr << is_of_length[i];
    cerr << "\n";
#endif
    fill_n(next_is_of_length, N, false);


    int intv_end = N - 1;
    while (intv_end >= 0) {
      int intv_start = intv_end;
      int last_good = -1;
      while (intv_start && sa.lcp[intv_start] >= length)
        --intv_start;
      debug(intv_start, intv_end);
      for (int i = intv_start; i <= intv_end; ++i)
        if (is_of_length[sa.suf[i]])
          maxi(last_good, sa.suf[i]);
      for (int i = intv_start; i <= intv_end; ++i) {
        const int pos = sa.suf[i];
        if (pos && last_good >= pos + length)
          next_is_of_length[pos - 1] = true;
        if (last_good > pos + length)
          next_is_of_length[pos] = true;
      }

      intv_end = intv_start - 1;
    }

    copy(next_is_of_length, next_is_of_length + N, is_of_length);
    ++length;
  }

  cout << length - 1 << "\n";

}