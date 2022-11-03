#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxb = 20;

vector<int> adj[maxn];

int h[maxn] , par[maxn][maxb];
int St[maxn] , ft[maxn] , id = -1;
int res[maxn] , ans , tmp[maxn];

set<pair<int , int> > st , shit;

void plant(int v , int p = -1)
{
	St[v] = ++id;

	for(auto u : adj[v])
		if(u != p)
		{
			par[u][0] = v;
			for(int i = 1; i < maxb; i++)
				par[u][i] = par[par[u][i - 1]][i - 1];

			h[u] = h[v] + 1;
			plant(u , v);
		}
	ft[v] = id;
}

bool is_par(int v , int u)
{
	return St[v] <= St[u] && St[u] <= ft[v];
}

int lca(int v , int u)
{
	for(int i = maxb - 1; i >= 0; i--)
		if(!is_par(par[v][i] , u))
			v = par[v][i];

	if(is_par(v , u))
		return v;
	else
		return par[v][0];
}

int dist(int v , int u)
{
	return h[v] + h[u] - 2 * h[lca(v , u)];
}

int nxt(int v)
{
	auto it = st.find({St[v] , v});

	it++;
	if(it == st.end())
		it = st.begin();

	return it -> second;
}

int pr(int v)
{
	auto it = st.find({St[v] , v});

	if(it == st.begin())
		it = st.end();
	it--;

	return it -> second;
}

void modify(int v)
{
	shit.erase({tmp[v] , v});
	
	tmp[v] = dist(v , nxt(v)) + dist(pr(v) , v) - dist(pr(v) , nxt(v));
	shit.insert({tmp[v] , v});
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	plant(0);

	for(int i = 0; i < n; i++)
		if((int)adj[i].size() == 1)
			st.insert({St[i] , i});

	int k = st.size();
	ans = 2 * (n - 1);
	for(int i = k; i <= n; i++)
		res[i] = ans / 2 + 1;

	for(auto x : st)
	{
		int v = x.second;
		
		modify(v);
	}

	for(int i = k - 1; i >= 1; i--)
	{
		int v = shit.begin() -> second;
		ans -= shit.begin() -> first;
		shit.erase(shit.begin());

		int a = pr(v) , b = nxt(v);
		st.erase({St[v] , v});

		modify(a);
		modify(b);

		res[i] = ans / 2 + 1;
	}

	for(int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;
}