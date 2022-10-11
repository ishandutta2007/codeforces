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

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

int n;
vector<int> a, where, start_a;
vector<pair<int, int>> ans;

void Main() {
  cin >> n;
  a.resize(n);
  vector<pair<int, int>> b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b.emplace_back(a[i], i);
  }
  start_a = a;
  sort(b.begin(), b.end());
  where.resize(n);
  for (int i = 0; i < n; i++) {
    where[b[i].second] = i;
  }
  for (int i = 0; i < n; i++) {
    vector<int> inds;
    for (int j = i + 1; j < n; j++) {
      if (start_a[i] > start_a[j]) {
        inds.push_back(j);
      }
    }
    sort(inds.begin(), inds.end(), [&](int &i, int &j) {
      return where[i] > where[j];
    });
    for (auto el : inds) {
      ans.emplace_back(i, el);
      swap(a[i], a[el]);
      swap(where[i], where[el]);
    }
  }
  assert(is_sorted(a.begin(), a.end()));
  cout << (int)ans.size() << '\n';
  for (auto [i, j] : ans) {
    cout << i + 1 << ' ' << j + 1 << '\n';
  }
}