#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

constexpr int N = 1e5, A = 10;
int a[N], n, d;
vector<array<int, 2>> byr[A];
int64_t bestloss = 2e18;
array<int, A> bestdrop{-1};

void finddrop(array<int, A> drop = {}, int64_t loss = 1, int dropped = 0) {
  if (loss >= bestloss || dropped == n) {
    return;
  }
  int p = 1;
  for (int i = 0; i < A; ++i) if (drop[i] < byr[i].size()) {
    (p *= byr[i].rbegin()[drop[i]][1]) %= A;
  }
  if (p == d) {
    bestloss = loss;
    bestdrop = drop;
    return;
  }
  if (dropped == 4) {
    return;
  }
  for (int i = 0; i < A; ++i) if (drop[i] < byr[i].size()) {
    auto tloss = loss * byr[i].rbegin()[drop[i]++][0];
    finddrop(drop, tloss, dropped + 1);
    --drop[i];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> d;
  int nn = 0;
  bool had1 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[nn];
    if (a[nn] == 1) {
      had1 = 1;
    } else if (d == 0 || d == 5 && a[nn] % 2 || d % 2 == 0 && a[nn] % 5 || d % 2 == 1 && a[nn] % 2 && a[nn] % 5) {
      byr[a[nn] % 10].push_back({a[nn], 0});
      ++nn;
    }
  }
  n = nn;
  {
    if (n == 0) {
      if (d == 1 && had1) {
        cout << "1\n1";
      } else {
        cout << -1;
      }
      return 0;
    }
    int p = 1;
    for (int i = 0; i < n; ++i) {
      p = p * a[i] % 10;
    }
    if (p == d) {
      cout << n << '\n';
      for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
      }
      return 0;
    } else if (d == 0) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 0; i < A; ++i) {
    sort(byr[i].begin(), byr[i].end(), greater<>{});
    for (int cp = 1, j = 0; j < byr[i].size(); ++j) {
      byr[i][j][1] = (cp *= byr[i][j][0]) %= 10;
    }
  }
  finddrop();
  if (bestdrop[0] == -1) {
    cout << -1;
    return 0;
  }
  vector<int> ans;
  for (int i = 0; i < A; ++i) {
    for (int j = 0; j < byr[i].size() - bestdrop[i]; ++j) {
      ans.push_back(byr[i][j][0]);
    }
  }
  cout << ans.size() << '\n';
  for (auto i: ans) {
    cout << i << ' ';
  }
}