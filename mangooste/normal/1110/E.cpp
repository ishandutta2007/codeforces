#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int n;
vector<int> a, b, da, db;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  b.resize(n);
  for (auto &el : b) {
    cin >> el;
  }
  for (int i = 1; i < n; i++) {
    da.push_back(a[i] - a[i - 1]);
    db.push_back(b[i] - b[i - 1]);
  }
  sort(da.begin(), da.end());
  sort(db.begin(), db.end());
  if (a[0] != b[0] || a.back() != b.back() || da != db) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}