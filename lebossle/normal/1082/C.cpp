#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > skill(m);
  for (int i=0; i<n; ++i) {
    int s, r;
    cin >> s >> r;
    skill[s-1].push_back(r);
  }
  for (int i=0; i<m; ++i)
    sort(skill[i].begin(), skill[i].end());
  vector<int> best(n, 0);
  for (int i=0; i<m; ++i) {
    int acum = 0;
    for (int j=0; j<skill[i].size(); ++j) {
      acum += skill[i][skill[i].size()-1-j];
      if (acum < 0)
        break;
      best[j] += acum;
    }
  }
  int ans = 0;
  for (int i=0; i<n; ++i)
    ans = max(ans, best[i]);
  cout << ans << endl;
}