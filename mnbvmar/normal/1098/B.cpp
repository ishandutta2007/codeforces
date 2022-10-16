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

int N, M;
vector<string> board;
vector<vector<int>> datax;
int mapping[256];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M;
  board.resize(N);
  datax.resize(N, vector<int>(M));

  mapping['A'] = 0;
  mapping['C'] = 1;
  mapping['G'] = 2;
  mapping['T'] = 3;

  for (int i = 0; i < N; ++i) {
    cin >> board[i];
    for (int j = 0; j < M; ++j) {
      datax[i][j] = mapping[(int)board[i][j]];
    }
  }

  bool best_flipped = false;
  int best_ans = 0;
  vector<PII> total_lineup;

  for (int bb : {0, 1}) {
    vector<vector<VI>> col_counts(2, vector<VI>(M, VI(4)));

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        ++col_counts[i % 2][j][datax[i][j]];
      }
    }

    debug(col_counts);

    bool is_best = false;
    vector<PII> best_lineup;

    for (int a = 0; a < 4; ++a) {
      for (int b = a + 1; b < 4; ++b) {
        int cur_ans = 0;

        int c = 0;
        while (c == a || c == b) { ++c; }
        int d = c + 1;
        while (d == a || d == b) { ++d; }

        vector<PII> lineups;
          debug("!");
        
        for (int col = 0; col < M; ++col) {
          int t[2];
          if (col % 2 == 0) {
            t[0] = a;
            t[1] = b;
          } else {
            t[0] = c;
            t[1] = d;
          }

          int best = -1;
          int who_best = -1;
          for (int i : {0, 1}) {
            const int col_gut =
              col_counts[0][col][t[i]] + col_counts[1][col][t[i ^ 1]];
            if (col_gut > best) {
              best = col_gut;
              who_best = i;
            }
          }

          cur_ans += best;

          lineups.emplace_back(t[who_best], t[who_best ^ 1]);
          debug(who_best, best);
        }

        if (cur_ans > best_ans) {
          debug(cur_ans, bb, a, b, lineups);
          is_best = true;
          best_lineup = lineups;
          best_ans = cur_ans;
        }
      }
    }

    if (is_best) {
      best_flipped = bb;
      total_lineup = best_lineup;
    }

    vector<VI> new_datax(M, VI(N));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        new_datax[j][i] = datax[i][j];
      }
    }

    datax = new_datax;
    swap(N, M);
  }

  debug(best_ans);

  const string kAlpha = "ACGT";

  if (!best_flipped) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        const int val = i % 2 == 0 ? total_lineup[j].st : total_lineup[j].nd;
        cout << kAlpha[val];
      }
      cout << "\n";
    }
  } else {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        const int val = j % 2 == 0 ? total_lineup[i].st : total_lineup[i].nd;
        cout << kAlpha[val];
      }
      cout << "\n";
    }
  }
}