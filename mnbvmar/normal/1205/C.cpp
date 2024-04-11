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

const int kMaxN = 55;

int tab[kMaxN][kMaxN];
int n;

int Ask(int r1, int c1, int r2, int c2) {
  cout << "? " << r1+1 << " " << c1+1 << " " << r2+1 << " " << c2+1 << endl;
  int ans;
  cin >> ans;
  return ans;
}

void Ans() {
  cout << "!\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << tab[i][j];
    }
    cout << endl;
  }
}

bool vis[55][55];

void Dfs(int r, int c) {
  vis[r][c] = true;
  for (int dr = -2; dr <= 2; ++dr) {
    for (int dc = -2; dc <= 2; ++dc) {
      if (abs(dr) + abs(dc) != 2) { continue; }
      if (dr < 0 && dc > 0) { continue; }
      if (dr > 0 && dc < 0) { continue; }
      const int nr = r + dr;
      const int nc = c + dc;
      if (nr < 0 || nc < 0 || nr >= n || nc >= n) { continue; }
      if (vis[nr][nc]) { continue; }
      debug(r, c, nr, nc);
      tab[nr][nc] = tab[r][c] ^ Ask(min(r,nr), min(c,nc), max(r,nr), max(c,nc)) ^ 1;
      Dfs(nr, nc);
    }
  }
}

int32_t main() {
  cin >> n;

  tab[0][0] = 1;
  tab[n-1][n-1] = 0;

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      if (r + c == 0 || r + c == 2 * n - 2) { continue; }
      if ((r + c) % 2 != 0) { continue; }
      int pr = -1, pc;
      for (int dr = 0; dr <= 2; ++dr) {
        const int dc = 2 - dr;
        if (r >= dr && c >= dc) {
          pr = r - dr; pc = c - dc; break;
        }
      }
      assert(pr >= 0);
      tab[r][c] = tab[pr][pc] ^ Ask(pr, pc, r, c) ^ 1;
    }
  }

  bool ok = false;
  for (int i = 2; i < n; ++i) {
    if (tab[i-2][i-2] != tab[i][i]) {
      bool eq = Ask(i-2, i-1, i-1, i);
      int val = -1;
      if (eq == (tab[i-2][i-2] == tab[i-1][i-1])) {
        val = Ask(i-2, i-2, i-1, i) ^ tab[i-1][i-1] ^ 1;
      } else {
        val = Ask(i-2, i-1, i, i) ^ tab[i][i] ^ 1;
      }
      debug(i-2, i-1, val);
      tab[i - 2][i - 1] = val;
      Dfs(i - 2, i - 1);
      ok = true;
      break;
    }
  }
  assert(ok);


  Ans();
}