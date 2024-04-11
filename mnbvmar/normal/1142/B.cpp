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

const int LogMaxN = 20;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int N, M, Q;
  cin >> N >> M >> Q;

  vector<int> perm(N), inv_perm(N);
  for (int i = 0; i < N; ++i) {
    cin >> perm[i];
    --perm[i];
    inv_perm[perm[i]] = i;
  }

  vector<int> seq(M);
  for (int i = 0; i < M; ++i) {
    cin >> seq[i];
    --seq[i];
  }

  vector<int> last_loc(N + 1, M + 2);
  vector<int> next_loc(M + 3, M + 2);

  vector<VI> next_jmp(M + 3, VI(LogMaxN, M + 2));

  for (int i = M - 1; i >= 0; --i) {
    const int val = seq[i];
    const int nxt = perm[(inv_perm[val] + 1) % N];
    if (last_loc[nxt] < M) {
      next_loc[i] = last_loc[nxt];
    }
    last_loc[val] = i;

    next_jmp[i][0] = next_loc[i];
    for (int j = 1; j < LogMaxN; ++j) {
      next_jmp[i][j] = next_jmp[next_jmp[i][j - 1]][j - 1];
    }
  }

  vector<int> last_jump(M);
  for (int i = 0; i < M; ++i) {
    last_jump[i] = i;
    for (int j = 0; j < LogMaxN; ++j) {
      if (((N - 1) & (1 << j))) {
        last_jump[i] = next_jmp[last_jump[i]][j];
      }
    }
  }

  debug(last_loc, next_loc, last_jump);

  for (int i = M - 2; i >= 0; --i) {
    mini(last_jump[i], last_jump[i + 1]);
  }

  for (int i = 0; i < Q; ++i) {
    int L, R;
    cin >> L >> R;
    --L; --R;
    bool ans = last_jump[L] <= R;
    cout << (ans ? "1" : "0");
  }
  cout << "\n";

}