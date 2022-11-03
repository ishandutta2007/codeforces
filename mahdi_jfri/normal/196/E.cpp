#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;

vector<int> adj[maxn];

int from[maxn] , to[maxn] , w[maxn] , pr[maxn] , par[maxn];

ll d[maxn] , res;

set<pair<ll , int> > st;

bool is[maxn];

int root(int v)
{
	return ((par[v] == -1)? v : par[v] = root(par[v]));
}

void dij()
{
	while(!st.empty())
	{
		int v = st.begin() -> second;
		ll dist = st.begin() -> first;
		st.erase(st.begin());
		if(dist != d[v])
			continue;
		for(auto e : adj[v])
		{
			int u = from[e] ^ to[e] ^ v;
			if(d[u] > d[v] + w[e])
			{
				d[u] = d[v] + w[e];
				pr[u] = pr[v];
				st.insert({d[u] , u});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fill(d , d + maxn , 1e15);
	fill(par , par + maxn , -1);
	int n , m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> from[i] >> to[i] >> w[i];
		from[i]--;
		to[i]--;
		adj[from[i]].pb(i);
		adj[to[i]].pb(i);
	}
	int k;
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		x--;
		d[x] = 0;
		is[x] = 1;
		st.insert({0 , x});
		pr[x] = x;
	}
	dij();
	vector<pair<ll , pair<int , int> > > edge;
	for(int i = 0; i < m; i++)
		edge.pb({d[from[i]] + d[to[i]] + w[i] , {pr[from[i]] , pr[to[i]]}});
	memset(par , -1 , sizeof par);
	sort(edge.begin() , edge.end());
	for(auto e : edge)
	{
		int v = e.second.first;
		int u = e.second.second;
		v = root(v);
		u = root(u);
		if(v == u)
			continue;
		res += e.first;
		par[v] = u;
	}
	st.clear();
	fill(d , d + maxn , 1e15);
	d[0] = 0;
	st.insert({0 , 0});
	dij();
	ll mn = 1e15;
	for(int i = 0; i < n; i++)
		if(is[i])
			mn = min(mn , d[i]);
	cout << res + mn << endl;
}