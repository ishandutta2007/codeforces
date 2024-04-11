#include<bits/stdc++.h>
#define broken cerr << __LINE__ <<" "<< __FUNCTION__ << endl
#define debug(x) cerr << #x <<" = " << x << endl
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
struct edge
{
  int to, nxt, w;
}e[N << 1];
int head[N], tot = 0;
int n, m;
int vis[N], mxd, id;
int sum[N], dr[N], cnt = 0, pa[N], used[N];
int dp[N], a[N], b[N], siz[N], anc[N], mp[N];
void adde(int u, int v, int w){e[++tot] = edge{v, head[u], w}, head[u] = tot;}
void dfs(int u, int fa, int dep)
{
  pa[u] = fa;
  if(vis[u] && dep > mxd) id = u, mxd = dep;
  for(int i = head[u]; i; i = e[i].nxt)
  {
    int v = e[i].to;
    if(v == fa) continue;
    dfs(v, u, dep + e[i].w);
  }
  return;
}


void gtag(int u, int fa, int *a, int dep)
{
  a[u] = dep;
  for(int i = head[u]; i; i = e[i].nxt)
  {
    int v = e[i].to;
    if(v == fa) continue;
    gtag(v, u, a, dep + e[i].w);
  }
  return;
}

void Dfs(int u, int fa, int rt)
{
  siz[u] = vis[u];
  anc[u] = rt;
  for(int i = head[u]; i; i = e[i].nxt)
  {
    int v = e[i].to;
    if(v == fa) continue;
    if(used[v]) continue;
    Dfs(v, u, rt);
    siz[u] += siz[v];
    dp[u] = max(dp[u], dp[v] + e[i].w);
  }
  return;
}


int main()
{
  // freopen("1.txt", "r", stdin);
  scanf("%d%d", &n, &m);
  int x;
  for(int i = 1; i <= m; i++) scanf("%d", &x), vis[x] = 1;
  int u, v, w;
  for(int i = 1; i < n; i++)
  {
    scanf("%d%d%d", &u, &v, &w);
    adde(u, v, w), adde(v, u, w);
  }
  id = mxd = -1;
  dfs(1, 0, 0);
  int s = id;
  id = mxd = -1;
  dfs(s, 0, 0);
  int t = id;
  swap(s, t);
  for(int now = s; now; now = pa[now]) dr[++cnt] = now, used[now] = 1, mp[now] = cnt;
  dr[cnt + 1] = n + 1;
  mp[n + 1] = cnt + 1;
  gtag(s, 0, a, 0);
  gtag(t, 0, b, 0);
  for(int i = 1; i <= cnt; i++) Dfs(dr[i], 0, dr[i]);
  int ans = 0;
  for(int i = 1; i <= n; i++) if(!used[i] && !vis[i]) ans = max(ans, siz[i]);
  for(int i = 1; i <= n; i++)
  {
    if(!vis[i]) continue;
    int u = anc[i];
    int d = max(a[u], b[u]);
    int k = mp[u];
    if(dp[u] == d || (a[u] == d && b[u] == d)) sum[k]++, sum[k + 1]--;
    else
    {
      if(a[u] == d) sum[0]++, sum[k + 1]--;
      else sum[k]++;
    }
  }
  for(int i = 1; i <= cnt; i++) sum[i] += sum[i - 1];
  for(int i = 1; i <= cnt; i++) if(!vis[dr[i]]) ans = max(ans, sum[i]);
  int amou = 0;
  for(int i = 1; i <= n; i++) if(!used[i] && !vis[i] && siz[i] == ans) amou++;
  for(int i = 1; i <= cnt; i++) if(!vis[dr[i]] && sum[i] == ans) amou++;
  printf("%d %d\n", ans, amou);
  return 0;
}