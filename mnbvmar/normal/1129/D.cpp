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

const int Mod = 998'244'353;
const int BlockLen = 170;
const int MaxN = 1e5 + 100;
const int NumBlocks = MaxN / BlockLen + 50;

int values[MaxN];
int dp[MaxN];
int N, K;

struct Block {
  int L, R;
  vector<PII> pref_sums;
  int ptr;
  int increase;
  VI num_incrs;

  Block() : L(0), R(0), ptr(0), increase(0) {}
  Block(int l, int r) : L(l), R(r), ptr(0), increase(0), num_incrs(r - l) {}

  void IncrAll(int delta) { increase += delta; }

  void Rebuild() {
    VI order(SZ(num_incrs));
    iota(ALL(order), 0);
    sort(ALL(order), [&](int lhs, int rhs) {
          return num_incrs[lhs] < num_incrs[rhs];
        });

    pref_sums.clear();
    pref_sums.emplace_back((int)-1e9, 0);
    pref_sums.emplace_back(num_incrs[order[0]], dp[order[0] + L]);

    for (int i = 1; i < SZ(order); ++i) {
      const int v = order[i];
      LL val = (pref_sums.back().nd + dp[v + L]) % Mod;
      if (num_incrs[v] == pref_sums.back().st) {
        pref_sums.back().nd = val;
      } else {
        pref_sums.emplace_back(num_incrs[v], val);
      }
    }
    ptr = 0;
    debug("Rebuild", pref_sums);
  }

  void IncrSeg(int lft, int rgt, int delta) {
    for (int i = 0; i < SZ(num_incrs); ++i) {
      num_incrs[i] += increase;
    }
    increase = 0;
    for (int i = lft - L; i < rgt - L; ++i) {
      num_incrs[i] += delta;
    }
    debug(num_incrs);
    Rebuild();
  }

  int GetAtMaxK() {
    while (ptr > 0 && pref_sums[ptr].st + increase > K) { --ptr; }
    while (ptr < SZ(pref_sums) - 1 && pref_sums[ptr + 1].st + increase <= K) { ++ptr; }
    debug("GetIn", L, R, ptr, pref_sums, increase, K);
    return pref_sums[ptr].nd;
  }
};

Block blocks[NumBlocks];


void Increase(int L, int R, int delta) {
  debug("Increase", L, R, delta);
  for (int i = 0; i < NumBlocks; ++i) {
    const int l_block = i * BlockLen;
    const int r_block = min((i + 1) * BlockLen, N + 1);
    if (l_block > N) { break; }
    if (r_block <= L || l_block >= R) { continue; }
    if (L <= l_block && r_block <= R) {
      blocks[i].IncrAll(delta);
    } else {
      blocks[i].IncrSeg(max<int>(L, l_block), min<int>(R, r_block), delta);
    }
  }
}

int GetAtMaxK() {
  int ans = 0;
  for (int i = 0; i < NumBlocks; ++i) {
    const int l_block = i * BlockLen;
    if (l_block > N) { break; }
    ans = (ans + blocks[i].GetAtMaxK()) % Mod;
  }
  debug("Get", ans);
  return ans;
}

void BuildBlocks() {
  for (int i = 0; i < NumBlocks; ++i) {
    const int l_block = i * BlockLen;
    const int r_block = min(N + 1, (i + 1) * BlockLen);
    if (l_block > N) { break; }
    debug(i, l_block, r_block);
    blocks[i] = Block(l_block, r_block);
    blocks[i].Rebuild();
  }
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> K;

#ifdef TEST
  for (int i = 0; i < N; ++i) { values[i] = i / 2 + 1; }
  srand(69);
  random_shuffle(values, values + N);
#else
  for (int i = 0; i < N; ++i) { cin >> values[i]; }
#endif

  dp[0] = 1;
  BuildBlocks();

  VI prev_occur(N + 1, 0), last_occur(N + 1, 0);

  for (int i = 1; i <= N; ++i) {
    const int v = values[i - 1];
    if (last_occur[v]) {
      Increase(prev_occur[v], last_occur[v], -1);
    }
    prev_occur[v] = last_occur[v];
    last_occur[v] = i;
    Increase(prev_occur[v], last_occur[v], 1);
    dp[i] = GetAtMaxK();
    blocks[i / BlockLen].Rebuild();
  }

  cout << dp[N] << "\n";
}