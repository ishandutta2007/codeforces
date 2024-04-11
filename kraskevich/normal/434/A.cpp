#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif // TEST

  int n, m;
  cin >> n >> m;
  vector<vector<int>> pr(n);
  vector<vector<int>> nx(n);
  vector<int> a(m);
  long long tot = 0;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
    if (i) {
      tot += labs(a[i] - a[i - 1]);
      pr[a[i]].push_back(a[i - 1]);
      nx[a[i - 1]].push_back(a[i]);
    } else {
      pr[a[i]].push_back(a[i]);
    }
  }
  nx[a[m - 1]].push_back(a[m - 1]);
  long long res = tot;
  for (int x = 0; x < n; x++) {
    if (!pr[x].size())
      continue;
    long long was = 0;
    for (int i = 0; i < pr[x].size(); i++)
      was += labs(x - pr[x][i]) + labs(x - nx[x][i]);
    vector<int> v;
    for (int i = 0; i < pr[x].size(); i++) {
      if (pr[x][i] != x)
        v.push_back(pr[x][i]);
      if (nx[x][i] != x)
        v.push_back(nx[x][i]);
    }
    sort(v.rbegin(), v.rend());
    long long now = 0;
    for (int i = 0; i < v.size(); i++)
      now += v[0] - v[i];
    long long best = now;
    for (int i = 1; i < v.size(); i++) {
      now += i * (v[i - 1] - v[i]);
      now -= ((int)v.size() - i) * (v[i - 1] - v[i]);
      best = min(best, now);
    }
    res = min(res, tot - was + best);
  }
  cout << res;

  return 0;
}