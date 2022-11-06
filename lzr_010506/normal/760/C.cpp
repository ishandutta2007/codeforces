#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n;
int Next[N], b[N], vis[N], cnt, tot;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void dfs(int u)
{
	if(vis[u]) return;
	vis[u] = 1;
	dfs(Next[u]);
}

int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
		Next[i] = read();
	for(int i = 1; i <= n; i ++)
		b[i] = read();
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		if(!vis[i])
		{
			cnt = 0;
			tot ++;
			dfs(i);
		}
	for(int i = 1; i <= n; i ++)
		if(b[i]) cnt ++;
	if(cnt % 2 == 0) ans ++;
	if(tot > 1) ans += tot;
	printf("%d\n",ans);
	return 0;
}