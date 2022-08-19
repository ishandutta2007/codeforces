#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> need(n);
  for (int i = 0; i < n; i++) {
    cin >> need[i];
  }
  int a;
  cin >> a;
  for (int i = 0; i < n; i++) {
    if (need[i] <= k) {
      need[i] = 0;
    } else {
      need[i] = (need[i] - k + a - 1) / a;
    }
    if (need[i] > i + 1) {
      cout << -1 << '\n';
      return 0;
    }
  }
  multiset <int> grab, free;
  vector <int> cost(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
    free.insert(cost[i]);
    while (grab.size() < need[i]) {
      sum += *free.begin();
      grab.insert(*free.begin());
      free.erase(free.begin());
    }
  }
  cout << sum << '\n';
}