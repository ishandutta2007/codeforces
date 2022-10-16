#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 1e5 + 1, Q = 1e5;

using ip = pair<int64_t, int64_t>;
ip queries[Q];
int64_t answers[Q];
int64_t a[N];
int64_t ftmax[N], ftmin[N];
vector<int> qbyl[N];

void add(int pos, int64_t val) {
  for (int i = pos; i < N; i |= i + 1) {
    ftmax[i] = max(ftmax[i], val);
    ftmin[i] = min(ftmin[i], val);
  }
}

ip query(int l, int r) {
  int64_t resmax = (-1ull >> 1) + 1, resmin = -1ull >> 1;
  for (int i = r; i > l; i &= i - 1) {
    resmax = max(resmax, ftmax[i - 1]);
    resmin = min(resmin, ftmin[i - 1]);
  }
  return {resmax - a[l - 1], resmin - a[l - 1]};
}

int main()
{
  cin.tie(0), ios::sync_with_stdio(0);
  for (int i = 0; i < N; ++i) {
    ftmax[i] = (-1ull >> 1) + 1;
    ftmin[i] = -1ull >> 1;
  }
  int n, q, t;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> t;
    a[i] = t - a[i];
    a[i] += a[i - 1];
  }
  for (int i = 0; i < q; ++i) {
    cin >> queries[i].first >> queries[i].second, ++queries[i].second;
    qbyl[queries[i].first].push_back(i);
  }
  for (int l = n; l; --l) {
    add(l, a[l]);
    for (auto i: qbyl[l]) {
      int r = queries[i].second;
      auto res = query(l, r);
      answers[i] = a[r - 1] != a[l - 1] || res.second < 0? -1: res.first;
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << answers[i] << '\n';
  }
  return 0;
}