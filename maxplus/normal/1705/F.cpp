#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <random>
#include <array>
#include <cassert>

using namespace std;

int n, x = 'F' ^ 'T';
vector<int> idxs;
string s, ans;
int q0;

int query(auto... args) {
  auto s = ::s;
  ((s[idxs[args]] ^= x), ...);
  cout << s << '\n';
  int res;
  cin >> res;
  if (res == n) {
    exit(0);
  }
  return res - q0;
}

int main() {
  cin >> n;
  idxs.resize(n);
  iota(idxs.begin(), idxs.end(), 0);
  shuffle(idxs.begin(), idxs.end(), mt19937(123));
  ans = s = string(n, 'F');
  q0 = query();
  vector<array<vector<int>, 2>> groups;
  for (int i = 0; i < n % 4; ++i) {
    if (query(i) > 0) {
      ans[i] ^= x;
    }
  }
  for (int i = n % 4; i < n; i += 4) {
    if (auto q = query(i, i + 1, i + 2, i + 3); q == 4) {
      ans[i] ^= x;
      ans[i + 1] ^= x;
      ans[i + 2] ^= x;
      ans[i + 3] ^= x;
    } else if (q != -4) {
      auto q2 = query(i, i + 1);
      if (q2 > 0) {
        ans[i] ^= x;
        ans[i + 1] ^= x;
      } else if (q2 == 0) {
        groups.push_back({{{i}, {i + 1}}});
      }
      if (q > q2) {
        ans[i + 2] ^= x;
        ans[i + 3] ^= x;
      } else if (q == q2) {
        groups.push_back({{{i + 2}, {i + 3}}});
      }
    }
  }
  while (groups.size() > 1) {
    auto a = groups.back(); groups.pop_back();
    auto b = groups.back(); groups.pop_back();
    if (auto q = query(a[0][0], b[1][0]); q == 0) {
      for (auto i: {0, 1}) {
        copy(b[i].begin(), b[i].end(), back_insert_iterator(a[i]));
      }
      groups.push_back(a);
    } else {
      for (auto c: {&a[q < 0], &b[q > 0]})
      for (auto i: *c) {
        ans[i] ^= x;
      }
    }
  }
  if (groups.size())
  for (auto i: groups[0][query(groups[0][0][0]) < 0]) {
    ans[i] ^= x;
  }
  for (int i = 0; i < n; ++i) {
    s[idxs[i]] = ans[i];
  }
  assert(query() + q0 == n);
}