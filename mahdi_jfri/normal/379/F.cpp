#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int maxb = 23;

int id = 1 , h[maxn] , par[maxn][maxb] , v , u;

int go(int v , int h)
{
	if(h == 0)
		return v;
	for(int i = 0; i < maxb; i++)
		if((h>>i)&1)
			v = par[v][i];
	return v;
}

int lca(int v , int u)
{
	if(h[v] > h[u])
		swap(v , u);

	u = go(u , h[u] - h[v]);

	if(u == v)
		return v;

	for(int i = maxb - 1; i >= 0; i--)
		if(par[v][i] != par[u][i])
			v = par[v][i] , u = par[u][i];

	return par[v][0];
}

int dist(int v , int u)
{
	return h[v] + h[u] - 2 * h[lca(v , u)];
}

void update(int w)
{
	if(dist(v , w) > dist(v , u))
		u = w;
	else if(dist(u , w) > dist(v , u))
		v = w;
}

void add(int v)
{
	h[id] = h[v] + 1;
	par[id][0] = v;

	for(int i = 1; i < maxb; i++)
		par[id][i] = par[par[id][i - 1]][i - 1];

	update(id);
	id++;
}

int main()
{
	int q;
	scanf("%d", &q);

	add(0);
	add(0);
	add(0);

	while(q--)
	{
		int p;
		scanf("%d", &p);
		p--;

		add(p);
		add(p);

		printf("%d\n", dist(v , u));
	}
}