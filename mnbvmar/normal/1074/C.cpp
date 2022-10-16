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

  int N;
  cin >> N;
  vector<PII> points(N);

  int max_x = -1e9;
  int max_y = -1e9;
  int min_x = 1e9;
  int min_y = 1e9;

  vector<PII> interesting_points;

  for (auto &[x, y] : points) {
    cin >> x >> y;
    maxi(max_x, x);
    maxi(max_y, y);
    mini(min_x, x);
    mini(min_y, y);
  }

  for (int cx : {-1, 0, 1})
    for (int cy : {-1, 0, 1})
      interesting_points.push_back(
          *max_element(ALL(points), [&](const PII &lhs, const PII &rhs) {
              return cx*lhs.st + cy*lhs.nd < cx*rhs.st + cy*rhs.nd;
            }));

  const int S = SZ(interesting_points);

  int best_3 = 0;

  for (int i = 0; i < S; ++i)
    for (int j = i + 1; j < S; ++j)
      for (int k = j + 1; k < S; ++k) {
        const PII A = interesting_points[i];
        const PII B = interesting_points[j];
        const PII C = interesting_points[k];
        maxi(best_3, abs(A.st-B.st)+abs(B.st-C.st)+abs(C.st-A.st)+
                     abs(A.nd-B.nd)+abs(B.nd-C.nd)+abs(C.nd-A.nd));

      }

  cout << best_3;
  for (int k = 4; k <= N; ++k)
    cout << " " << 2 * (max_x - min_x + max_y - min_y);
  cout << "\n";


}