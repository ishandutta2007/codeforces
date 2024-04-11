#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n), c(n);
  for (int i=0; i<n; ++i)
    cin >> p[i] >> c[i];
  vector<vector<lli> > v(m);
  for (int i=0; i<n; ++i)
    v[p[i]-1].push_back(c[i]);
  for (int i=0; i<m; ++i)
    sort(v[i].begin(), v[i].end());
  lli best = 10000000000000LL;
  for (int votes=1; votes<=n; ++votes) {
    lli bribe=0;
    int curvotes = v[0].size();
    vector<lli> extra;
    for (int i=1; i<m; ++i) {
      for (int j=0; j<(int)(v[i].size())-votes+1; ++j) {
        bribe += v[i][j];
        curvotes++;
      }
      for (int j=max(0,(int)(v[i].size())-votes+1); j<v[i].size(); ++j)
        extra.push_back(v[i][j]);
    }
    sort(extra.begin(), extra.end());
    for (int i=0; i<votes-curvotes; ++i)
      bribe += extra[i];
    best = min(best, bribe);
  }
  cout << best << endl;
}