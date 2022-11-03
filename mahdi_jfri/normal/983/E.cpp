// gonah dashtam :'((((((((

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int maxb = 20;

int h[maxn] , st[maxn] , ft[maxn] , id = -1 , par[maxn][maxb];

vector<int> adj[maxn] , shit[maxn];

vector<pair<int , int> > query[maxn];

set<int> sv[maxn];

int from[maxn] , to[maxn] , mid[maxn] , F[maxn][maxb];

int ans[maxn];

void predfs(int v , int p = -1)
{
	st[v] = ++id;

	for(auto u : adj[v])
		if(u != p)
		{
			par[u][0] = v;
			for(int i = 1; i < maxb; i++)
				par[u][i] = par[par[u][i - 1]][i - 1];
			
			h[u] = h[v] + 1;

			predfs(u , v);
		}

	ft[v] = id;
}

bool is_par(int v , int u)
{
	return (st[v] <= st[u] && st[u] <= ft[v]);
}

int lca(int v , int u)
{
	for(int i = maxb - 1; i >= 0; i--)
		if(!is_par(par[v][i] , u))
			v = par[v][i];

	if(is_par(v , u))
		return v;

	return par[v][0];
}

void CalF(int v , int p = -1)
{
	F[v][0] = v;
	for(auto u : adj[v])
		if(u != p)
		{
			CalF(u , v);

			int tmp = F[u][0];
			if(h[tmp] < h[F[v][0]])
				F[v][0] = tmp;
		}

	for(auto tmp : shit[v])
		if(h[mid[tmp]] < h[F[v][0]])
			F[v][0] = mid[tmp];
}

int node;

int get(int v , int u)
{
	int res = 0;
	for(int i = maxb - 1; i >= 0; i--)
		if(h[F[v][i]] > h[u])
			v = F[v][i] , res += (1 << i);

	node = v;

	if(h[v] == h[u])
		return 0;

	return res + 1;
}

void merge(int v , int u)
{
	if(sv[v].size() < sv[u].size())
		sv[v].swap(sv[u]);

	for(auto tmp : sv[u])
		sv[v].insert(tmp);
	sv[u].clear();
}

void lanat(int v , int p = -1)
{
	for(auto u : adj[v])
		if(u != p)
			lanat(u , v) , merge(v , u);

	for(auto tmp : shit[v])
		sv[v].insert(st[from[tmp]^to[tmp]^v]);

	for(auto tmp : query[v])
	{
		int u = tmp.first;
		int id = tmp.second;

		auto it = sv[v].lower_bound(st[u]);

		if(it != sv[v].end() && (*it) <= ft[u])
			ans[id]--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i < n; i++)
	{
		int a , b = i;
		cin >> a;
		a--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	predfs(0);

	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		if(st[a] > st[b])
			swap(a , b);

		shit[a].pb(i);
		shit[b].pb(i);

		from[i] = a , to[i] = b , mid[i] = lca(a , b);
	}

	CalF(0);

	for(int i = 1; i < maxb; i++)
		for(int j = 0; j < n; j++)
			F[j][i] = F[F[j][i - 1]][i - 1];

	int q;
	cin >> q;

	for(int i = 0; i < q; i++)
	{
		int v , u;
		cin >> v >> u;
		v-- , u--;

		if(st[v] > st[u])
			swap(v , u);

		int c = lca(v , u);

		if(h[F[v][maxb - 1]] > h[c] || h[F[u][maxb - 1]] > h[c])
		{
			ans[i] = -1;
			continue;
		}

		int res = 0;

		if(v == c)
		{
			ans[i] = get(u , v);
			continue;
		}

		res += get(v , c);
		int v1 = node;

		res += get(u , c);
		int u1 = node;

		ans[i] = res;

		query[v1].pb({u1 , i});
	}

	lanat(0);

	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;

}