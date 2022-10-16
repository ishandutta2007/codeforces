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
  vector<vector<LD>> dp;
  int N;
  LD C, T;
  vector<PII> tasks;

  void Run() {
    cin >> N >> C >> T;
    tasks.resize(N);
    int total_points = 0;

    const LD kCoef = (LD)10 / 9;

    for (auto &[a, p] : tasks) {
      cin >> a >> p;
      total_points += p;
    }
    sort(ALL(tasks));

    dp.resize(N + 1, vector<LD>(total_points + 1, 1e18));

    dp[0][0] = 0;
    int so_far = 0;
    for (auto [a, p] : tasks) {
      ++so_far;
      debug(a, p);

      for (int cnt = so_far; cnt > 0; --cnt)
        for (int tot = total_points; tot >= p; --tot)
          mini(dp[cnt][tot], kCoef * (a + dp[cnt - 1][tot - p]));
    }

    for (int i = 0; i <= N; ++i)
      debug(i, dp[i]);

    for (int tot = total_points; tot >= 0; --tot) {
      for (int cnt = 0; cnt <= N; ++cnt) {
        if (10 * cnt > T) { continue; }
        const LD min_coef = dp[cnt][tot];
        const LD a = 1;
        const LD b = -(C * (T - 10 * cnt) + 1);
        const LD c = C * min_coef;
        LD delta = b * b - 4 * a * c;
        if (delta >= 0) {
          delta = sqrt(delta);
          // const LD x1 = (-b - delta) / (2 * a);
          const LD x2 = (-b + delta) / (2 * a);
          if (x2 > 1) {
            debug(tot, cnt, min_coef);
            debug(a, b, c, delta);
            cout << tot << "\n";
            return;
          }
        }
      }
    }

    cout << "0\n";
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int T;
  cin >> T;
  for (int i = 0; i < T; ++i)
    Testcase().Run();
}