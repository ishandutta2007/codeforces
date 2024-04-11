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

const int MaxN = 1e6 + 100;

int xi[MaxN], yi[MaxN];
LL ai[MaxN];
int N;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> xi[i] >> yi[i] >> ai[i];
  }

  vector<int> order(N);
  iota(ALL(order), 0);
  sort(ALL(order), [&](int lhs, int rhs) {
        return xi[lhs] < xi[rhs];
      });


  xi[N] = 0;
  yi[N] = 2e9;

  
  vector<LL> x_stack{0};
  vector<LL> best_stack{0};
  LL best_ans = 0;

  int lptr = 0;

  for (int v : order) {
    const int x = xi[v], y = yi[v];
    const LL a = ai[v];

    debug(x, y, a, x_stack, best_stack);

    while (lptr < SZ(x_stack) - 1) {
      const LL area1 = (x - x_stack[lptr]) * y;
      const LL area2 = (x - x_stack[lptr+1]) * y;
      const LL cand1 = best_stack[lptr] + area1 - a;
      const LL cand2 = best_stack[lptr+1] + area2 - a;
      if (cand2 > cand1) {
        ++lptr;
      } else {
        break;
      }
    }

    const LL area = (x - x_stack[lptr]) * y;
    const LL cand = best_stack[lptr] + area - a;
    debug(x_stack, lptr, cand);
    maxi(best_ans, cand);
    if (cand > best_stack.back()) {
      while (SZ(x_stack) > 1) {
        const int s = SZ(x_stack);
        const int maxx1 = (best_stack[s-1] - best_stack[s-2]) / (x_stack[s-1] - x_stack[s-2]);
        const int maxx2 = (cand - best_stack[s-1]) / (x - x_stack[s-1]);
        if (maxx1 <= maxx2) {
          debug(maxx1, maxx2);
          x_stack.pop_back();
          best_stack.pop_back();
          mini(lptr, SZ(x_stack));
        } else break;
      }
      x_stack.PB(x);
      best_stack.PB(cand);
    }
  }

#ifdef LOCAL
  vector<LL> dp(N + 1, -1e18);
  dp[0] = 0;
  for (int i = 0; i < N; ++i) {
    const int v = order[i];
    const int x = xi[v];
    int who = -1;
    for (int j = 0; j <= i; ++j) {
      const int prev_x = j == 0 ? 0 : xi[order[j - 1]];
      const LL c = dp[j] + (LL)(x - prev_x) * yi[v] - ai[v];
      if (c > dp[i + 1]) {
        dp[i + 1] = c;
        who = j;
      }
    }

    debug(i, who);
  }

  const LL gut = *max_element(ALL(dp));
  debug(dp, gut, best_ans);
  assert(gut == best_ans);
#endif

  cout << best_ans << "\n";
}