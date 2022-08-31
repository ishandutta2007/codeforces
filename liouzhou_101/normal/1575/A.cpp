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
    int n, m;
    read(n), read(m);
    vector<pair<string, int>> v;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int j = 1; j < m; j += 2)
        s[j] = 'a' + (25 - (s[j] - 'a'));
      v.emplace_back(s, i);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
      cout << v[i].second + 1 << " ";
    cout << endl;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}