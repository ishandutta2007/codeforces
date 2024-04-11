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

struct Tree {
  int Base;
  vector<int> data;

  Tree(int N) : Base(1) {
    while (Base < N + 2) { Base *= 2; }
    data.resize(Base * 2);
  }

  void Add(int v, int p) {
    v += Base;
    while (v) {
      data[v] += p;
      v /= 2;
    }
  }

  int GetSum(int L, int R) {
    if (L > R) { return 0; }
    L += Base; R += Base;
    if (L == R) { return data[L]; }
    int ans = data[L] + data[R];

    while (L / 2 != R / 2) {
      if (L % 2 == 0) { ans += data[L + 1]; }
      if (R % 2 == 1) { ans += data[R - 1]; }
      L /= 2; R /= 2;
    }
    return ans;
  }
};

const int MaxN = 2048;
const int Mod = 998'244'353;

int N;
int matrix[MaxN][MaxN];
int derang[MaxN][MaxN];

int PowMod(int a, int n) {
  int r = 1;
  while (n) {
    if (n & 1) { r = (LL)r * a % Mod; }
    n >>= 1;
    a = (LL)a * a % Mod;
  }
  return r;
}

void MakeDerangements() {
  derang[0][0] = 1;
  derang[1][0] = 1;
  derang[1][1] = 0;

  for (int n = 2; n <= N; ++n) {
    derang[n][0] = ((LL)derang[n - 1][0] * n) % Mod;

    for (int k = 1; k <= n; ++k) {
      derang[n][k] = (LL)(k - 1) * derang[n - 1][k - 1] % Mod;
      derang[n][k] = (derang[n][k] + (LL)(n - k) * derang[n - 1][k]) % Mod;
      derang[n][k] = (derang[n][k] + (LL)(n - k) * derang[n - 2][k - 1]) % Mod;
      if (k >= 2) {
        derang[n][k] = (derang[n][k] + (LL)(k - 1) * derang[n - 2][k - 2]) % Mod;
      }
      assert(derang[n][k] >= 0);
    }
  }
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      cin >> matrix[i][j];

  MakeDerangements();

  debug(derang[2][0]);
  debug(derang[2][1]);
  debug(derang[2][2]);
  debug(derang[3][3]);

  int answer = 0;

  Tree full_tree(N + 1);
  for (int i = 1; i <= N; ++i)
    full_tree.Add(i, 1);

  for (int row = 0; row < N; ++row) {
    const int row_coef = PowMod(derang[N][N], N - row - 1);
    debug(row, row_coef);

    vector<bool> is_seen(N + 1);
    vector<bool> is_top(N + 1);
    if (row) {
      for (int j = 1; j <= N; ++j)
        is_top[j] = true;
    }

    int occur_right = row ? N : 0;

    Tree right_occur = full_tree;
    Tree right_nooccur(N + 1);


    if (!row) {
      swap(right_occur, right_nooccur);
    }

    for (int col = 0; col < N; ++col) {
      const int val = matrix[row][col];
      debug(right_occur.GetSum(0, 2));
      
      int num_decr = right_occur.GetSum(0, val - 1);
      int num_nodecr = right_nooccur.GetSum(0, val - 1);
      assert(num_decr >= 0);
      if (row && val > matrix[row - 1][col] && !is_seen[matrix[row - 1][col]]) {
        --num_decr;
      }
      int decr_base = row ?
        occur_right - !is_seen[matrix[row - 1][col]] : 0;
      int decr_mod = max<int>(0, decr_base - 1);

      assert(decr_base >= 0);

      int coef =
        ((LL)num_decr * derang[N - col - 1][decr_mod] +
         (LL)num_nodecr * derang[N - col - 1][decr_base]) % Mod;

      debug(row, col, coef, num_decr, num_nodecr, decr_base, decr_mod);

      answer = (answer + (LL)row_coef * coef) % Mod;

      is_seen[val] = true;
      if (is_top[val]) {
        debug("SubOccur", val);
        right_occur.Add(val, -1);
      } else {
        right_nooccur.Add(val, -1);
      }

      if (row) {
        const int top = matrix[row - 1][col];
        is_top[top] = false;
        if (!is_seen[top]) {
          debug("SubOccur", top);
          right_occur.Add(top, -1);
          right_nooccur.Add(top, 1);
        }
      }

      occur_right = decr_base;
      if (is_top[val]) {
        --occur_right;
      }
      assert(occur_right >= 0);

      debug(answer);
    }
  }

  cout << answer << "\n";
}