#include <cstdio>
#include <iostream>
#include <algorithm>
#define MN 201000

typedef std::pair<int, int> P;
int a[MN], b[MN], e[MN];
int c[MN], d[MN], C[MN];
int g[MN], f[MN], h[MN], F[MN], G[MN], H[MN];
int Max[MN], id[MN];
int n, m, N, M;
bool used[MN];

void rw(int &a, int &b, int c, int d) {if(c >= a) a = c, b = d;}

void add(int x, int v, int V) {for(int i = x; i <= N; i += i & -i) rw(c[i], C[i], v, V);}
P query(int x) {int ans = 0, id = 0; for(int i = x; i; i -= i & -i) rw(ans, id, c[i], C[i]); return P(ans, id);}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {scanf("%d", &a[i]); if(a[i] != -1) d[++N] = a[i];}
	a[++n] = 2e9; d[++N] = a[n];
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]), d[++N] = b[i];
	std::sort(b + 1, b + m + 1);
	std::sort(d + 1, d + N + 1); N = std::unique(d + 1, d + N + 1) - d - 1;
	for(int i = 1; i <= n; i++) if(a[i] != -1) a[i] = std::lower_bound(d + 1, d + N + 1, a[i]) - d;
	for(int i = 1; i <= m; i++) b[i] = std::lower_bound(d + 1, d + N + 1, b[i]) - d, e[i] = b[i];
	M = std::unique(e + 1, e + m + 1) - e - 1;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == -1)
		{
			int o = 1;
			int Maxx = 0, idd = 0;
			for(int j = 1; j <= N; j++)
			{
				if(o <= M && e[o] == j)
				{
					h[o] = g[o - 1] + 1; H[o] = G[o - 1];
					rw(h[o], H[o], Maxx + 1, idd);
					o++;
				}
				rw(Maxx, idd, Max[j], id[j]);
			}
			for(int j = 1; j <= N; j++) g[j] = h[j], G[j] = H[j];
		}
		else
		{
			P p = query(a[i] - 1);
			f[i] = p.first + 1; F[i] = p.second;
			int u = std::lower_bound(e + 1, e + M + 1, a[i]) - e;
			if(u - 1 >= 1) rw(f[i], F[i], g[u - 1] + 1, G[u - 1]);
			add(a[i], f[i], i);
			rw(Max[a[i]], id[a[i]], f[i], i);
		}
	}
//	printf("%d\n", f[n] - 1);
	int now = n;
	while(f[now] > 1)
	{
		int lst = F[now];
		int u = std::upper_bound(e + 1, e + M + 1, a[lst]) - e;
		int cnt = f[now] - f[lst] - 1;
		for(int i = lst; i <= now; i++)
			if(a[i] == -1 && cnt)
			{
				used[e[u]] = 1, a[i] = e[u++], cnt--;
			}
		now = lst;
	}
	int j = 1;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == -1)
		{
			while(b[j] != b[j - 1] && used[b[j]]) j++;
			a[i] = b[j]; j++;
		}
		a[i] = d[a[i]];
	}
	for(int i = 1; i <= n - 1; i++) printf("%d ", a[i]);
}