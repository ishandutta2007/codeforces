#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> g[100010];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, f[100010], ans, G[100010], H[100010];
int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
		f[i] = read();
	bool flag = 1;
	for (int i = 1; i <= n; i ++)
		if (f[i] != i && f[f[i]] != f[i])
			flag = 0;
	if(flag == 0) {cout << -1; return 0;}
	for(int i = 1; i <= n; i ++) g[f[i]].pb(i);
	for(int i = 1; i <= n; i ++)
		if(f[i] == i)
		{
			ans ++;
			for (int j = 0; j < g[f[i]].size(); j ++)
				G[g[f[i]][j]] = ans;
			H[ans] = i;
		}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i ++) printf("%d ", G[i]);
	puts("");
	for (int i = 1; i <= ans; i ++) printf("%d ", H[i]);
	return 0;
}