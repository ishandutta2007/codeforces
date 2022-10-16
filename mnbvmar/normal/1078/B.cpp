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

const int MaxN = 105;
int weights[MaxN];
int N;
bool dp_left[MaxN][MaxN][MaxN * MaxN];
bool dp_right[MaxN][MaxN][MaxN * MaxN];
int num_known[MaxN][MaxN * MaxN];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> weights[i];

  sort(weights, weights + N);

  dp_left[0][0][0] = dp_right[0][0][0] = true;
  for (int i = 0; i < N; ++i) {
    const int a = weights[i];
    for (int k = 1; k <= i + 1; ++k)
      for (int j = k * MaxN; j >= a; --j)
        dp_left[i+1][k][j] |= dp_left[i][k - 1][j - a];

    const int b = weights[N - i - 1];
    for (int k = 1; k <= i + 1; ++k)
      for (int j = k * MaxN; j >= b; --j)
        dp_right[i+1][k][j] |= dp_right[i][k - 1][j - b];

    for (int k = 0; k <= i + 1; ++k)
      for (int j = 0; j <= k * MaxN; ++j) {
        dp_left[i + 1][k][j] |= dp_left[i][k][j];
        dp_right[i + 1][k][j] |= dp_right[i][k][j];
      }
  }

  int answer = 0;

  map<int, int> counts;
  int total = 0;
  for (int i = 0; i < N; ++i) {
    ++counts[weights[i]];
    total += weights[i];
  }

  debug(dp_left[1][1][1]);
  debug(dp_left[4][3][7]);

  for (auto [w, cnt] : counts) {
    int fst = 0;
    while (weights[fst] != w) { ++fst; }

    for (int taken = 1; taken <= cnt; ++taken) {
      const int x = w * taken;
      const int lst = fst + cnt - taken + 1;
      debug(w, taken, fst, N-lst);
      bool fail = false;
      
      for (int lft_s = 0; lft_s <= taken; ++lft_s)
        for (int lft_w = 0; lft_w <= x; ++lft_w)
          if (dp_left[fst][lft_s][lft_w] && dp_right[N - lst][taken - lft_s][x - lft_w]) {
            fail = true;
            break;
          }

      if (!fail) {
        debug(w, taken);
        int cand = taken;
        if (taken == cnt && SZ(counts) == 2)
          cand = N;
        maxi(answer, cand);
      }
    }
  }

  cout << answer << "\n";

}