#include <algorithm>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
using ll = long long;

mt19937 rng(random_device{}());
mt19937_64 rng64(random_device{}());

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
  vector<int> ans;

  void dfs(vector<vector<int>> &root, int l, int r) {
    int rt = root[l][r];
    if (l < rt) {
      ans[root[l][rt - 1]] = rt;
      dfs(root, l, rt - 1);
    }
    if (rt < r) {
      ans[root[rt + 1][r]] = rt;
      dfs(root, rt + 1, r);
    }
  }

 public:
  void solve() {
    int n;
    read(n);
    vector<vector<ll>> c(n + 1, vector<ll>(n + 1)),
        pc(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        read(c[i][j]);
        pc[i][j] = pc[i - 1][j] + pc[i][j - 1] - pc[i - 1][j - 1] + c[i][j];
      }
    }

    auto query = [&](int x1, int y1, int x2, int y2) {
      if (x1 > x2 || y1 > y2) return 0LL;

      return pc[x2][y2] - pc[x1 - 1][y2] - pc[x2][y1 - 1] + pc[x1 - 1][y1 - 1];
    };

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, LLONG_MAX));
    vector<vector<int>> root(n + 1, vector<int>(n + 1));
    ans = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i) dp[i][i] = query(i, 1, i, n), root[i][i] = i;

    for (int len = 2; len <= n; ++len) {
      for (int l = 1; l + len - 1 <= n; ++l) {
        int r = l + len - 1;
        for (int k = l; k <= r; ++k) {
          ll cost = 0;
          if (k > l) cost += dp[l][k - 1];
          if (k < r) cost += dp[k + 1][r];
          if (cost < dp[l][r]) {
            dp[l][r] = cost;
            root[l][r] = k;
          }
        }
        dp[l][r] += query(l, 1, r, l - 1) + query(l, r + 1, r, n);
      }
    }

    dfs(root, 1, n);

    for (int i = 1; i <= n; i++) {
      if (ans[i] == 0)
        printf("0 ");
      else
        printf("%d ", ans[i]);
    }
    printf("\n");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}