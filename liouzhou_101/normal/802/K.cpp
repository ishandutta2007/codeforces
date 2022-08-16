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

const int MAXN = 111111;

int n, k;
vector<pii> v[MAXN];
int F[MAXN], G[MAXN];

void build(int x, int p)
{
	vector<int> wG;
	for (auto y : v[x])
	{
		if (y.X == p) continue;
		build(y.X, x);
		wG.push_back(G[y.X]+y.Y);
	}
	sort(wG.begin(), wG.end(), greater<int>());
	
	multiset<int> hG;
	G[x] = 0;
	for (int i = 0; i < k && i < wG.size(); ++ i)
	{
		G[x] += wG[i];
		hG.insert(wG[i]);
	}
	
	F[x] = 0;
	for (auto y : v[x])
	{
		if (y.X == p) continue;
		if (hG.count(G[y.X]+y.Y))
			F[x] = max(F[x], G[x]-(G[y.X]+y.Y)+(F[y.X]+y.Y));
		else
			F[x] = max(F[x], G[x]-*hG.begin()+(F[y.X]+y.Y));
	}
	
	if (hG.size() == k)
		G[x] -= *hG.begin();
}

int main()
{
	
	scanf("%d%d", &n, &k);
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
		ans = max(ans, F[i]);
	printf("%d\n", ans);
	
	return 0;
}