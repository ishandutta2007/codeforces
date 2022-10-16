#include <algorithm>
#include <iostream>
#include <array>

using namespace std;

constexpr int N = 100;

int res[N][N];
array<int, 2> cres[N];
int ans[N];
int n, m;

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i)
  for (int j = 0; j < n; ++j) {
    cin >> res[i][j];
  }
  int ans = 1e9;
  for (int w = 0; w < n - 1; ++w) {
    for (int i = 0; i < m; ++i) {
      cres[i] = {res[i][n - 1] - res[i][w], i};
    }
    sort(cres, cres + m);
    int b = 0, i = 0;
    while (i < m && (b += cres[i][0]) <= 0) {
      ++i;
    }
    if (ans > m - i) {
      ans = m - i;
      for (int j = i; j < m; ++j) {
        ::ans[j - i] = cres[j][1];
      }
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < ans; ++i) {
    cout << ::ans[i] + 1 << ' ';
  }
}