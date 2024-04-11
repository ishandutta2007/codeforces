#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 3e3 + 10;
int n;
db x[N], y[N], d[N][N];
bitset<N> s[N];
int id[N * N], u[N * N], v[N * N], tot = 0;
int cmp(int x, int y)
{
  return d[u[x]][v[x]] > d[u[y]][v[y]];
}
int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%lf%lf", &x[i], &y[i]);
  for(int i = 1; i <= n; i++)
  {
    for(int j = i + 1; j <= n; j++)
    {
      d[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      u[++tot] = i, v[tot] = j, id[tot] = tot;
    }
  }
  sort(id + 1, id + tot + 1, cmp);
  for(int i = 1; i <= tot; i++)
  {
    int l = u[id[i]], r = v[id[i]];
    if((s[l] & s[r]).count() > 0) return printf("%.10lf\n", d[l][r] / 2), 0;
    s[r].set(l, 1), s[l].set(r, 1);
  }
  assert(0);
  return 0;
}