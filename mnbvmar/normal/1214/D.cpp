#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define st first
#define nd second
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

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ld = long double;

const int kMaxN = 1e6 + 100;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};

vi adj[kMaxN * 2];
int prev_vert[kMaxN * 2];
bool vis[kMaxN * 2];
int dest;

bool Dfs(int v, int p) {
  vis[v] = true;
  prev_vert[v] = p;
  if (v == dest) { return true; }
  for (int s : adj[v]) {
    if (s == -1) { continue; }
    //cout << v << " -> " << s << "\n";
    if (!vis[s] && Dfs(s, v)) { return true; }
  }
  return false;
}

void Rev() {
  int ptr = dest;
  while (true) {
    int prev = prev_vert[ptr];
    if (prev == -1) { break; }
    for (int &x : adj[prev]) {
      if (x == ptr) { x = -1; }
    }
    //cout << prev << " " << " ";
    adj[ptr].push_back(prev);
    ptr = prev;
  }
  //cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  int n, m;
  cin >> n >> m;
  vector<string> board(n);
  for (string &s : board) { cin >> s; }

  auto GetId = [&](int r, int c) {
    return r * m + c;
  };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] != '.') { continue; }
      const int my_id = GetId(i, j);
      adj[my_id * 2].push_back(my_id * 2 + 1);
      if (i && board[i-1][j] == '.') {
        adj[GetId(i-1, j) * 2 + 1].push_back(my_id * 2);        
      }
      if (j && board[i][j-1] == '.') {
        adj[GetId(i, j-1) * 2 + 1].push_back(my_id * 2);
      }
    }
  }

  int ans = 0;
  const int src = 1;
  dest = GetId(n - 1, m - 1) * 2;
  while (true) {
    fill_n(vis, n * m * 2, false);
    if (!Dfs(src, -1)) { break; }
    Rev();
    ++ans;
  }

  cout << ans << "\n";
}