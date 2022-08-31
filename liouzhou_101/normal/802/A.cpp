#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 444444;

int n, k;
int a[MAXN], nxt[MAXN];
int c[MAXN];
int u[MAXN];

int main()
{
	
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++ i)
		c[i] = n+1;
	for (int i = n; i >= 1; -- i)
	{
		nxt[i] = c[a[i]];
		c[a[i]] = i;
	}
	int ans = 0;
	set<pii> Q;
	for (int i = 1; i <= n; ++ i)
	{
		if (u[a[i]])
		{
			Q.erase(pii(i, a[i]));
			Q.insert(pii(nxt[i], a[i]));
			continue;
		}
		ans ++;
		if (Q.size() == k)
		{
			auto it = --Q.end();
			u[it->Y] = 0;
			Q.erase(it);
		}
		Q.insert(pii(nxt[i], a[i]));
		u[a[i]] = 1;
	}
	printf("%d\n", ans);
	
	return 0;
}