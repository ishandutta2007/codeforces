#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<pair<int, int>> v;
  string s; cin >> s;
  for (auto c: s) {
    if (v.size() && c == v.back().first) {
      ++v.back().second;
    } else {
      v.emplace_back(c, 1);
    }
  }
  bool ok = v.size() % 2;
  for (int i = 0; i < v.size(); ++i) {
    ok &= v[i].first == v.rbegin()[i].first && v[i].second + v.rbegin()[i].second >= 3;
  }
  int ans{};
  if (ok) {
    ans = v[v.size() / 2].second + 1;
  }
  cout << ans << '\n';
}