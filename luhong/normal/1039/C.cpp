#include <cstdio>
#include <algorithm>
#define mod 1000000007

struct xxx {int u, v; long long c;}e[1010000];

int ans, n, m, k;
long long c[1010000], mi[1010000];
int fa[1010000];

int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}

void hb(int u, int v)
{
	u = Find(u), v = Find(v);
	if(u == v) return;
	ans--; fa[u] = v;
}

bool cmp(xxx a, xxx b) {return a.c < b.c;}

void qpow(int x)
{
	
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	mi[0] = 1;
	for(int i = 1; i <= n; i++) scanf("%lld", &c[i]), mi[i] = mi[i - 1] * 2 % mod;
	for(int i = 1; i <= m; i++) scanf("%d%d", &e[i].u, &e[i].v), e[i].c = c[e[i].u] ^ c[e[i].v];
	std::sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	long long Ans = 0;
	int cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		cnt++;
		int j = i;
		while(i + 1 <= m && e[i + 1].c == e[j].c) i++;
		ans = n;
		for(int k = j; k <= i; k++)
			hb(e[k].u, e[k].v);
		Ans = (Ans + mi[ans]) % mod;
		for(int k = j; k <= i; k++) fa[e[k].u] = e[k].u, fa[e[k].v] = e[k].v;
	}
	Ans = (Ans + mi[n] * (((1ll << k) - cnt) % mod) % mod) % mod;
	printf("%lld\n", Ans);
	return 0;
}