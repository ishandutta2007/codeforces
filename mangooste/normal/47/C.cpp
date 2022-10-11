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

vector<string> s(6), dict(6);
vector<vector<string>> solutions;

void Main() {
  for (auto &el : s) {
    cin >> el;
  }
  vector<int> inds(6);
  iota(inds.begin(), inds.end(), 0);
  do {
    for (int i = 0; i < 6; i++) {
      dict[i] = s[inds[i]];
    }
    if ((int)(dict[0].size() + dict[4].size()) - 1 == (int)dict[2].size()) {
      if ((int)(dict[1].size() + dict[5].size()) - 1 == (int)dict[3].size()) {
        if (dict[0][0] == dict[1][0] && dict[2][0] == dict[1].back() && dict[0].back() == dict[3][0]) {
          if (dict[2].back() == dict[5][0] && dict[4][0] == dict[3].back() && dict[4].back() == dict[5].back()) {
            if (dict[2][dict[0].size() - 1] == dict[3][dict[1].size() - 1]) {
              vector<string> cur(dict[3].size(), string(dict[2].size(), '.'));
              for (int i = 0; i < (int)dict[0].size(); i++) {
                cur[0][i] = dict[0][i];
              }
              for (int i = 0; i < (int)dict[1].size(); i++) {
                cur[i][0] = dict[1][i];
              }
              for (int i = 0; i < (int)dict[2].size(); i++) {
                cur[dict[1].size() - 1][i] = dict[2][i];
              }
              for (int i = 0; i < (int)dict[3].size(); i++) {
                cur[i][dict[0].size() - 1] = dict[3][i];
              }
              for (int i = 0; i < (int)dict[4].size(); i++) {
                cur[dict[3].size() - 1][dict[0].size() + i - 1] = dict[4][i];
              }
              for (int i = 0; i < (int)dict[5].size(); i++) {
                cur[dict[1].size() + i - 1][dict[2].size() - 1] = dict[5][i];
              }
              solutions.push_back(cur);
            }
          }
        }
      }
    }
  } while (next_permutation(inds.begin(), inds.end()));
  if (solutions.empty()) {
    cout << "Impossible\n";
    return;
  }
  vector<string> ans = *min_element(solutions.begin(), solutions.end());
  for (auto &el : ans) {
    cout << el << '\n';
  }
}