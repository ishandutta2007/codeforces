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
#define MOD 998244353

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
 public:
  void solve() {
    int n, m;
    read(n), read(m);
    int amax = 0, bmax = 0;
    for (int i = 0; i < m; ++i) {
      int a, b;
      read(a), read(b);
      amax = max(amax, a);
      bmax = max(bmax, b);
    }

    if (amax + bmax > n) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      int b = n - amax;
      cout << string(amax, 'R') + string(b, 'W') << endl;
    }
  }
};

int main() {
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}