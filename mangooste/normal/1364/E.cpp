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

mt19937 rng(time(NULL));
int n;
map<pair<int, int>, int> queries;

int ask(int pos1, int pos2) {
  if (pos1 > pos2) {
    swap(pos1, pos2);
  }
  if (queries.find(make_pair(pos1, pos2)) != queries.end()) {
    return queries[make_pair(pos1, pos2)];
  }
  cout << "? " << pos1 + 1 << ' ' << pos2 + 1 << endl;
  int cur;
  cin >> cur;
  assert(cur != -1);
  queries[make_pair(pos1, pos2)] = cur;
  return cur;
}

int find_zero(vector<int> inds, int small) {
  if ((int)inds.size() == 1) {
    return inds[0];
  }
  map<int, vector<int>> cur;
  for (auto el : inds) {
    if (el != small) {
      cur[ask(el, small)].push_back(el);
    }
  }
  int cnt = 0;
  for (auto el : cur) {
    if (__builtin_popcount(el.first) == 1) {
      cnt++;
    }
  }
  if (cnt > 1) {
    return small;
  }
  auto it = cur.begin();
  return find_zero(it->second, it->second[rng() % (int)it->second.size()]);
}

void Main() {
  cin >> n;
  int small = -1;
  for (int q = 230;; q--) {
    int a = rng() % n, b = rng() % n;
    if (a == b) {
      b = (b + 1) % n;
    }
    if ((1 << __builtin_popcount(ask(a, b)) + 1) < q) {
      small = a;
      break;
    }
    q--;
  }
  vector<int> inds(n);
  iota(inds.begin(), inds.end(), 0);
  int zero = find_zero(inds, small);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (i != zero) {
      ans[i] = ask(zero, i);
    }
  }
  cout << "!";
  for (auto el : ans) {
    cout << ' ' << el;
  }
  cout << endl;
}