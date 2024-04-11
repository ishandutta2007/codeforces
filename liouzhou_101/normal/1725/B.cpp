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
public:
  void solve() {
    int n, d;
    read(n), read(d);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    sort(a.rbegin(), a.rend());
    int ans = 0;
    int r = n;
    for (int l = 0; l < r; ++l) {
      int need = d / a[l] + 1;
      if (r - l < need)
        break;
      r -= need - 1;
      ans++;
    }
    printf("%d\n", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}