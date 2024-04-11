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

const int kRows[4] = {0, -1, 0, 1};
const int kCols[4] = {-1, 0, 1, 0};
const int kCost[4] = {1, 0, 0, 0};

const int MaxN = 2048;

int dist[MaxN][MaxN];
deque<pair<int, int>> Q;

int N, M;
int r0, c0;
int x, y;
char board[MaxN][MaxN];
bool visited[MaxN][MaxN];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M >> r0 >> c0 >> x >> y;
  --r0; --c0;
  for (int i = 0; i < N; ++i)
    cin >> board[i];

  Q.push_back(make_pair(r0, c0));

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      dist[i][j] = 1e9;
  dist[r0][c0] = 0;
  
  while (!Q.empty()) {
    auto [r, c] = Q.front();
    Q.pop_front();

    if (visited[r][c]) { continue; }
    visited[r][c] = true;
    debug(r, c, dist[r][c]);

    for (int d = 0; d < 4; ++d) {
      const int nr = r + kRows[d];
      const int nc = c + kCols[d];
      const int ncost = kCost[d];
      if (nr < 0 || nr >= N) { continue; }
      if (nc < 0 || nc >= M) { continue; }
      if (board[nr][nc] == '*') { continue; }
      if (dist[nr][nc] > dist[r][c] + ncost) {
        dist[nr][nc] = dist[r][c] + ncost;
        if (ncost)
          Q.push_back(make_pair(nr, nc));
        else
          Q.push_front(make_pair(nr, nc));
      }
    }
  }

  int answer = 0;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) {
      const int left = dist[i][j];
      if (left > 1e8) { continue; }
      debug(i, j, left);
      const int right = j - (c0 - left);
      answer += (left <= x && right <= y);
    }

  cout << answer << "\n";
}