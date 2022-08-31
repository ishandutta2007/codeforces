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

const int MAXN = 111;

int n;
vector<pii> v[MAXN];
int d[MAXN];

void build(int x, int p)
{
	for (auto y : v[x])
	{
		if (y.X == p) continue;
		d[y.X] = d[x]+y.Y;
		build(y.X, x);
	}
}

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i < n; ++ i)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		x ++;
		y ++;
		v[x].push_back(pii(y, c));
		v[y].push_back(pii(x, c));
	}
	build(1, 0);
	int ans = 0;
	for (int i = 1; i <= n; ++ i)
		ans = max(ans, d[i]);
	printf("%d\n", ans);
	
	return 0;
}