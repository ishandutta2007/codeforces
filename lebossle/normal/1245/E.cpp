#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}

typedef long double num;

int tr(int i, int j) {
  return (9-i)*10 + (i%2==0 ? 9-j : j);
}

void solve() {
  vector<vector<int>> grid(10, vector<int>(10));
  for (auto& v : grid)
    for (int& i : v)
      cin >> i;
  vector<int> jump(100, -1);
  for (int i=0; i<10; ++i)
    for (int j=0; j<10; ++j)
      jump[tr(i, j)] = tr(i-grid[i][j], j);
  vector<num> ans(100);
  ans[99] = 0;
  for (int i=98; i>=0; --i) {
    num sum = 0; int amt = 0;
    for (int j=1; j<=6; ++j)
      if (i+j <= 99) {
        amt++;
        sum += min(ans[i+j], ans[jump[i+j]]);
      }
    // ans = 1 + (ans*(6-amt) + sum)/6
    ans[i] = (6 + sum)/amt;
  }
  printf("%.8Lf\n", ans[0]);
}