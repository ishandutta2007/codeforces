#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull INF = numeric_limits<ull>::max();

int main() {
  ios_base::sync_with_stdio(0);

  ull n, m;
  cin >> n >> m;
  vector<ull> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<ull> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<ull> fa(n);
  vector<ull> fb(m);
  ull sa = 0;
  ull sb = 0;
  ull res = INF;
  for(int i = 0; i < n; i++) {
    fa[i] = sa;
    sa += a[i];
  }
  for (int i = 0; i < m; i++) {
    fb[i] = sb;
    sb += b[i];
  }
  for (ull i = 0; i < n; i++)
    res = min(res, fa[i] + (n - i) * sb);
  for (ull i = 0; i < m; i++)
    res = min(res, fb[i] + (m - i) * sa);

  cout << res;

  return 0;
}