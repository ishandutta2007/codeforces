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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int M, A, B;

  cin >> M >> A >> B;
  
  const int S = 2 * (A + B) + 3;

  vector<int> min_reach(S, -1);
  min_reach[0] = 0;

  for (int last = 1; last < S; ++last) {
    if (last < A || min_reach[last - A] == -1) { continue; }
    min_reach[last] = last;
    queue<int> Q;
    Q.push(last);

    while (!Q.empty()) {
      const int v = Q.front();
      Q.pop();

      for (int s : {v + A, v - B}) {
        if (0 <= s && s <= last && min_reach[s] == -1) {
          min_reach[s] = last;
          Q.push(s);
        }
      }
    }
  }

  const int g = gcd(A, B);
  vector<int> increase(S);
  for (int i = 0; i < S; ++i) {
    if (min_reach[i] != -1) {
      ++increase[min_reach[i]];
    }
  }

  LL ans = 0;
  LL cur_val = 0;
  int last_seen = 0;
  for (int i = 0; i < S && i <= M; ++i) {
    cur_val += increase[i];
    ans += cur_val;
    last_seen = i;
  }

  while (last_seen < M && (last_seen + 1) % g != 0) {
    ans += cur_val;
    ++last_seen;
  }
  debug(last_seen);

  const int num_whole_steps = (M - last_seen) / g;
  debug(num_whole_steps);
  ans += cur_val * num_whole_steps * g;
  ans += (LL)num_whole_steps * (num_whole_steps + 1) / 2 * g;
  last_seen += num_whole_steps * g;
  cur_val += num_whole_steps + 1;
  while (last_seen < M) {
    ans += cur_val;
    ++last_seen;
  }

  debug(last_seen);

  cout << ans << "\n";

}