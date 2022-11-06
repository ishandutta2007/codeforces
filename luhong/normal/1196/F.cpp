#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MN 401000

typedef long long ll;
int a[MN];
struct xxx{
	int u, v, c;
}e[MN];
ll f[810][810];
ll d[810 * 810];

bool cmp(xxx a, xxx b) {return a.c < b.c;}

int main()
{
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
	std::sort(e + 1, e + m + 1, cmp);
	
	int N = 0;
	for(int i = 1; i <= std::min(m, k); i++) a[++N] = e[i].u, a[++N] = e[i].v;
	std::sort(a + 1, a + N + 1); N = std::unique(a + 1, a + N + 1) - a - 1; 
	
	memset(f, 0x3f, sizeof(f)); 
	for(int i = 1; i <= std::min(m, k); i++)
	{
		int U = std::lower_bound(a + 1, a + N + 1, e[i].u) - a;
		int V = std::lower_bound(a + 1, a + N + 1, e[i].v) - a;
		f[U][V] = f[V][U] = e[i].c;  
	}
	
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			if(f[i][k] <= 1e18)	
			for(int j = 1; j <= N; j++)
				f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
	
	int tot = 0;
	for(int i = 1; i <= N; i++)
		for(int j = i + 1; j <= N; j++) d[++tot] = f[i][j];
	
	std::sort(d + 1, d + tot + 1);
	printf("%lld\n", d[k]);
}