//#ifdef DEBUG
//#define _GLIBCXX_DEBUG
//#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

constexpr int N = 228'228;
constexpr int M = 500;

vector<int> all[N];


namespace checker {

std::array<int, N> used;
int color;

void iterate() {
  color++;
}

bool was(int i) {
  return used[i] == color;
}

bool visit(int i) {
  used[i] = color;
}

}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> b;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      b.emplace_back(x, i);
    }
  }
  sort(b.begin(), b.end());
  int i = 0;
  int cnt_sets = 0;
  while (i < b.size()) {
    int j = i;
    while (j < b.size() && b[j].first == b[i].first) {
      j++;
    }
    all[cnt_sets].clear();
    all[cnt_sets].reserve(j - i);
    for (; i < j; i++) {
      all[cnt_sets].emplace_back(b[i].second);
    }
    cnt_sets++;
  }
  for (int i = 0; i < cnt_sets; i++) {
    if (all[i].size() < M) {
      continue;
    }
    checker::iterate();
    for (auto x : all[i]) {
      checker::visit(x);
    }
    for (int j = 0; j < cnt_sets; j++) {
      if (j == i) {
        continue;
      }
      int y = -1;
      for (auto x : all[j]) {
        if (checker::was(x)) {
          if (y == -1) {
            y = x;
          } else {
            cout << x + 1 << " " << y + 1 << "\n";
            return;
          }
        }
      }
    }
  }
  vector<vector<int>> keks(n);
  for (int i = 0; i < cnt_sets; i++) {
    if (all[i].size() >= M) {
      continue;
    }
    for (int j = 0; j < all[i].size(); j++) {
      for (int k = j + 1; k < all[i].size(); k++) {
        keks[min(all[i][j], all[i][k])].emplace_back(max(all[i][j], all[i][k]));
      }
    }
  }
  for (int x = 0; x < n; x++) {
    checker::iterate();
    for (auto y : keks[x]) {
      if (checker::was(y)) {
        cout << x + 1 << " " << y + 1 << "\n";
        return;
      }
      checker::visit(y);
    }
  }
  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  for (; t >= 1; t--) {
    solve();
  }
  return 0;
}