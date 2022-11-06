#include <bits/stdc++.h>
#define N 1010
using namespace std;
int n, mn[N], g[N], f[2][N][N], cnt[2][N];
bool mk[N];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void solve(int l, int r, int dep)
{
	int mid = (l + r) >> 1;
	if(l == r) return;
	solve(l, mid, dep + 1);
	solve(mid + 1, r, dep + 1);
	for(int i = l; i <= mid; i ++) f[0][dep][++ cnt[0][dep]] = i;
	for(int i = mid + 1; i <= r; i ++) f[1][dep][++ cnt[1][dep]] = i;
}

void work(int l, int r, int dep)
{
	int mid = (l + r) >> 1;
	if(l == r) return;
	for(int i = 0; i < 2; i ++)
	{
		if(cnt[i][dep] == 0) continue;
		memset(mk, 0, sizeof(mk));
		printf("%d\n", cnt[i][dep]);
		for(int j = 1; j < cnt[i][dep]; j ++)
			printf("%d ", f[i][dep][j]), mk[f[i][dep][j]] = 1;
		printf("%d\n",f[i][dep][cnt[i][dep]]);
		fflush(stdout);
		mk[f[i][dep][cnt[i][dep]]] = 1;
		for(int j = 1; j <= n; j ++)
		{
			g[j] = read();
			if(!mk[j]) mn[j] = min(mn[j], g[j]);
		}
	}
	work(l, mid, dep + 1);
}

int main()
{
	n = read();
	for(int i = 1; i <= n; i ++) mn[i] = 1e9;
	solve(1, n, 1);
	work(1, n, 1);
	printf("-1\n");
	for(int i = 1; i < n; i ++)
		printf("%d ", mn[i]);
	printf("%d\n", mn[n]);
	fflush(stdout);
	return 0;
}