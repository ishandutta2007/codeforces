#include <cstdio>
#include <iostream>
#include <cstring>
#define MN 101000

typedef long long ll;

ll c0[MN], c1[MN], c2[MN];
int n;
int a[MN];
double ans = 0;
ll now = 0;

void ins(ll *c, int x, ll v) {for(int i = x; i <= n; i += i & -i) c[i] += v;}
ll query(ll *c, int x) {ll ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

int main()
{
	scanf("%d", &n); double tot = 1ll * n * (n + 1) / 2;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	memset(c0, 0, sizeof(c0)); now = 0;
	for(int i = 1; i <= n; i++)
	{
		now += (i - 1 - query(c0, a[i])); 
		ins(c0, a[i], 1);
		ans += now * (n - i) / tot;
	}
	
	memset(c0, 0, sizeof(c0)); now = 0;
	for(int i = n; i >= 1; i--)
	{
		now += query(c0, a[i]); 
		ins(c0, a[i], 1);
		ans += now * (i - 1) / tot;
	}
	
	for(int i = 1; i <= n; i++)
		ans += 1ll * (n - i + 1) * i * (i - 1) / 4.0 / tot; 
	
	now = 0;
	for(int i = 1; i <= n; i++)
	{
		now += a[i] - i;
		ans += now * n / tot;
	}
	
	memset(c0, 0, sizeof(c0));
	for(int i = n; i >= 1; i--)
	{
		ans -= (query(c2, a[i]) - (2 * i + 1) * query(c1, a[i]) + (1ll * i * i + i) * query(c0, a[i])) / 2.0 / tot;
		ins(c0, a[i], 1);
		ins(c1, a[i], i);
		ins(c2, a[i], 1ll * i * i);
	}
	
	printf("%.15lf\n", ans);
}