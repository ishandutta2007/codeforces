#include <bits/stdc++.h>
using namespace std;
const int N = (3e5 + 200)*10;
int fst[N],nxt[2*N],vv[2*N],ecnt;
void add(int u,int v)
{
	vv[ecnt] = v;nxt[ecnt] = fst[u];fst[u] = ecnt++;
	vv[ecnt] = u;nxt[ecnt] = fst[v];fst[v] = ecnt++;
}
int ch[N][26], c[N], diff[N];
char s[N];
int n, tot;
int merge(int u,int v)
{
	if(u < 0) return v;
	if(v < 0) return u;
	int t = ++ tot;
	diff[t] = 1;
	for(int i = 0; i < 26; i ++)
	{
		ch[t][i] = merge(ch[u][i], ch[v][i]);
		if(ch[t][i] >= 0) diff[t] += diff[ch[t][i]];
	}
	return t;
}
void dfs(int u,int fa)
{
	memset(ch[u], -1, sizeof(ch[u]));	
	for(int i = fst[u]; ~i; i = nxt[i])
	{
		int v = vv[i];
		if(v == fa) continue;
		dfs(v,u);
		int nx = s[v] - 'a';
		ch[u][nx] = merge(ch[u][nx],v);
	}
	diff[u] = 1;
	for(int i = 0; i < 26; i ++)
	{
		if(ch[u][i] != -1)
			diff[u] += diff[ch[u][i]];
	}
}
int main()
{
	cin >> n;
	memset(fst,-1,sizeof(fst));
	for(int i = 1; i <= n; i ++)
		scanf("%d", &c[i]);
	scanf("%s", s + 1);
	for(int i = 0; i < n - 1; i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u, v);
	}
	tot = n;
	dfs(1, 0);
	int ans = -1,cnt = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(diff[i] + c[i] > ans)
		{
			ans = diff[i] + c[i];
			cnt = 1;
		}
		else if(diff[i] + c[i] == ans) cnt ++;
	}
	cout << ans << endl << cnt << endl;
	return 0;
}