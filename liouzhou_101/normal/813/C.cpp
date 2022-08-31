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

const int MAXN = 222222;

int n, s;
vector<int> v[MAXN];

int dis[MAXN], pre[MAXN];
int md[MAXN];

void build(int x, int p)
{
	md[x] = dis[x];
	for (auto y : v[x])
	{
		if (y == p) continue;
		dis[y] = dis[x]+1;
		pre[y] = x;
		build(y, x);
		md[x] = max(md[x], md[y]);
	}
}

int main()
{
	
	scanf("%d%d", &n, &s);
	for (int i = 1; i < n; ++ i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	build(1, 0);
	int x = s;
	if (dis[x]%2 == 0)
	{
		int k = dis[x]/2-1;
		for (int i = 1; i <= k; ++ i)
			x = pre[x];
		int ans = k*2+(md[x]-dis[x])*2+4;
		cout << ans << endl;
	}
	else
	{
		int k = dis[x]/2;
		for (int i = 1; i <= k; ++ i)
			x = pre[x];
		int ans = k*2+(md[x]-dis[x])*2+2;
		cout << ans << endl;
	}
	
	return 0;
}