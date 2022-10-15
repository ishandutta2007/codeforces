#include <iostream>
#include <algorithm>
#include <vector>
const int mxN = 1e5 + 5;
int a[mxN], b[mxN], p[mxN << 1], idx[mxN];
int set_of(int x) {
  return p[x] == x ? x : p[x] = set_of(p[x]);
}
bool cmp(int aa, int bb) {
  return a[aa] > a[bb];
}
bool cmp2(int aa, int bb) {
  return b[aa] > b[bb];
}
bool cmp3(std::pair<std::pair<int, int>, int> aa, std::pair<std::pair<int, int>, int> bb) {
  return aa.second > bb.second;
}
void eat() {
  int m, n;
  std::cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
    idx[i] = i;
  }
  std::sort(idx + 1, idx + m + 1, cmp);
  for (int i = 1; i <= n; i++) std::cin >> b[i];
  for (int i = 1; i <= m + n; i++) p[i] = i;
  std::vector<int> adj[m + 1];
  for (int i = 1, x; i <= m; i++) {
    std::cin >> x;
    while (x--) {
      int z;
      std::cin >> z;
      adj[i].push_back(z);
    }
  }
  std::vector<std::pair<std::pair<int, int>, int > > fuck;
  for (int i = 1; i <= m; i++) {
    std::sort(adj[idx[i]].begin(), adj[idx[i]].end(), cmp2);
    for(auto j : adj[idx[i]]) fuck.push_back({{i + n, j}, a[idx[i]] + b[j]});
  }
  std::sort(fuck.begin(), fuck.end(), cmp3);
  long long ans = 0; // fucking shit
  for (auto i : fuck) {
    i.first.first = set_of(i.first.first);
    i.first.second = set_of(i.first.second);
    if (i.first.first == i.first.second) ans += i.second;
    else p[i.first.second] = i.first.first;
  }
  std::cout << ans << "\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}