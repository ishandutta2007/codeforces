#include <bits/stdc++.h>
using namespace std;
 
#define fora(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define ford(i, r, l) for (int i = (int)(r); i >= (int)(l); --i)
 
constexpr int MOD = 1e9 + 7;
constexpr int INF = INT32_MAX;
constexpr int MAXN = 2e6 + 10;
constexpr double eps = 1e-8;
 
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using Vec = vector<int>;
 
template <class T> void Min(T &a, T b) {if (b < a) a = b;}
template <class T> void Max(T &a, T b) {if (b > a) a = b;}
 
ll N, M, K, T;
Vec A;
vector<Vec> ans;
vector<Vec> dirs = {{2, 0}, {-2, 0}, {0, 2}, {0, -2}, {1, 1}, {-1, -1}};
 
bool Query(int a, int b, int c, int d) {
  if (a + b >= c + d + 2) {
    swap(a, c);
    swap(b, d);
  }
  cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
  int res;
  cin >> res;
  return res;
}
 
inline bool Inside(int x, int y) {
  return 0 < x && x <= N && 0 < y && y <= N;
}
 
void dfs(int x, int y) {
  for (auto &d : dirs) {
    int nx = x + d[0], ny = y + d[1];
    if (Inside(nx, ny) && ans[nx][ny] == -1) {
      bool p = Query(x, y, nx, ny);
      if (p) {
        ans[nx][ny] = ans[x][y];
      } else {
        ans[nx][ny] = ans[x][y] ^ 1;
      }
      dfs(nx, ny);
    }
  }
}
 
int FindStart() {
  for (int i = 1; i + 2 <= N; i += 2) {
    if (ans[i][i] == 1 && ans[i+2][i+2] == 0)
      return i;
  }
  return -1;
}
 
void Solution() {
  ans[1][1] = 1, ans[N][N] = 0;
  dfs(1, 1), dfs(N, N);
  int st = FindStart();
  assert(st != -1);
  if (Query(st, st, st + 1, st + 2)) {
    ans[st+1][st+2] = 1;
    dfs(st+1, st+2);
  } else if (Query(st + 1, st, st + 2, st + 2)) {
    ans[st+1][st] = 0;
    dfs(st+1, st);
  } else if (ans[st+1][st+1]) {
    if (ans[st][st+2] == 0) {
      ans[st+1][st+2] = 0;
      dfs(st+1, st+2);
    } else if (ans[st+2][st] == 0) {
      ans[st+1][st] = 1;
      dfs(st+1, st);
    } else {
      ans[st+1][st+2] = 0;
      dfs(st+1, st+2);
    }
  } else {
    if (ans[st][st+2] == 1) {
      ans[st+1][st+2] = 0;
      dfs(st+1, st+2);
    } else if (ans[st+2][st] == 1) {
      ans[st+1][st] = 1;
      dfs(st+1, st);
    } else {
      ans[st+1][st] = 1;
      dfs(st+1, st);
    }
  }
  cout << "!" << endl;
  fora (i, 0, N) {
    fora (j, 0, N) {
      cout << ans[i+1][j+1];
    }
    cout << endl;
  }
}
 
int main() {
#ifdef MY_DEBUG
  freopen("../in.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> N) {
    ans.assign(N+1, Vec(N+1, -1));
    Solution();
  }
  return 0;
}