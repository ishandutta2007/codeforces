#include <iostream>
#include <queue>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, m, x, a;
  cin >> t;
  while (t--) {
    cin >> n >> m >> x;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < m; ++i) {
      pq.emplace(0, i + 1);
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      cin >> a;
      cout << pq.top().second << ' ';
      pq.emplace(pq.top().first + a, pq.top().second);
      pq.pop();
    }
    cout << '\n';
  }
  return 0;
}