#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 10;
int n, m, k;
int c[N], flag = 0;
int fa[N * 2], pa[N * 2], prop[N];
map<pii, vector<pii> > but;
set<pii> G;
int st[N * 2], top = 0, vis[N * 2];
int find(int x)
{
  if(fa[x] == x) return x;
  if(!vis[x]) st[++top] = x, vis[x] = 1;
  return fa[x] = find(fa[x]);
}
 
void merge(int u, int v)
{
  u = find(u), v = find(v);
  if(u == v) return;
  if(!vis[u]) st[++top] = u, vis[u] = 1;
  fa[u] = v;
  return;
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= 2 * n; i++) fa[i] = i;
  for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
  int u, v;
  for(int i = 1; i <= m; i++)
  {
    scanf("%d%d", &u, &v);
    if(c[u] == c[v])
    {
      merge(u, v + n);
      merge(v, u + n);
    }
    else
    {
      int cu = c[u], cv = c[v];
      if(cu > cv) swap(cu, cv);
      if(u > v) swap(u, v);
      but[mp(cu, cv)].push_back(mp(u, v));
    }
  }
  for(int i = 1; i <= n; i++) if(find(i) == find(i + n)) prop[c[i]] = 1;
  for(int i = 1; i <= 2 * n; i++) pa[i] = fa[i];
  top = 0;
  for(int i = 1; i <= 2 * n; i++) vis[i] = 0;
  for(map<pii, vector<pii> >::iterator it = but.begin(); it != but.end(); it++)
  {
  	set<int> s;
    int flag = 0;
    int cu = it -> first.first, cv = it -> first.second;
    if(prop[cu] || prop[cv]) continue;
    for(int i = 0; i < it -> second.size(); i++)
    {
      int u = (it -> second)[i].first;
      int v = (it -> second)[i].second;
      merge(u, v + n);
      merge(v, u + n);
      s.insert(u), s.insert(v);
    }
    for(set<int>::iterator jt = s.begin(); jt != s.end(); jt++) if(find((*jt)) == find((*jt) + n)) flag = 1;
    if(flag) G.insert(mp(it -> first.first, it -> first.second));
    for(int i = 1; i <= top; i++) fa[st[i]] = pa[st[i]], vis[st[i]] = 0;
    top = 0;    
  }
  int cnt = 0;
  for(int i = 1; i <= k; i++) if(prop[i]) cnt++;
  ll all = k - cnt;
  all = all * (all - 1) / 2;
  for(set<pii>::iterator it = G.begin(); it != G.end(); it++)
  {
    int u = it -> first;
    int v = it -> second;
    if(prop[u] || prop[v]) continue;
    all--;
  }
  printf("%lld\n", all);
  return 0;
}