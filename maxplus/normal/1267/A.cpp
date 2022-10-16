#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

bool dead[200000];

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<array<int64_t, 3>> masters(n);
  vector<pair<int64_t, int>> events;
  for (int i = 0; i < n; ++i) {
    cin >> masters[i][0] >> masters[i][1] >> masters[i][2];
    events.push_back({masters[i][0] + masters[i][2], ~i});
    events.push_back({masters[i][1], i});
  }
  sort(events.begin(), events.end());
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;
  int64_t last = 0, ans = 0;
  for (auto [t, i]: events) {
    if (i >= 0) {
      auto top = pq.top();
      if (i == top.second) {
        auto r = (masters[i][1] - last) / top.first;
        ans += r, last += r * top.first;
      }
      dead[i] = 1;
      while (pq.size() && dead[pq.top().second]) {
        pq.pop();
      }
    } else {
      i = ~i;
      if (pq.empty() || masters[i][0] <= last) {
        last = max(last, masters[i][0]);
      } else if (auto top = pq.top(); masters[i][0] + masters[i][2] <=
                      last + (masters[i][0] - last + top.first - 1) / top.first * top.first) {
        ans += (masters[i][0] - last) / top.first;
        last = masters[i][0];
      } else {
        auto r = (masters[i][0] - last + top.first - 1) / top.first;
        ans += r, last += r * top.first;
      }
      pq.push({masters[i][2], i});
    }
  }
  cout << ans << '\n';
}