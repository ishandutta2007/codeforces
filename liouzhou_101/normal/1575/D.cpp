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

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
  string s;
  int n, ans, x;

  void dfs(int acc, int pos) {
    if (pos == n) {
      if (acc % 25 == 0 && (acc > 0 || n == 1))
        ans++;
    } else {
      if (s[pos] == 'X') {
        if (pos >= 1 || x > 0)
          dfs(acc * 10 + x, pos + 1);
      } else if (s[pos] == '_') {
        int lb = pos == 0 ? 1 : 0;
        for (int i = lb; i <= 9; ++i) {
          dfs(acc * 10 + i, pos + 1);
        }
      } else {
        dfs(acc * 10 + s[pos] - '0', pos + 1);
      }
    }
  }

public:
  void solve() {
    cin >> s;
    ans = 0;
    n = s.size();
    if (n == 1) {
      if (s == "_" || s == "X" || s == "0")
        printf("1\n");
      else
        printf("0\n");
      return;
    }
    int xl = 0;
    for (char ch : s) {
      if (ch == 'X')
        xl = 9;
    }
    for (x = 0; x <= xl; ++x) {
      dfs(0, 0);
    }
    printf("%d\n", ans);
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}