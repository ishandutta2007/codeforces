#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int maxb = 21;

vector<int> adj[maxn] , out[maxn];

int st[maxn] , ft[maxn] , rst[maxn] , now , par[maxn][maxb];

int a[maxn] , tmpst[maxn] , h[maxn];

ll res;

bool is[maxn];

int W(int v , int u)
{
	return abs(h[v] - h[u]);
}

void set_dfs(int v)
{
	now++;
	st[v] = now;
	rst[now] = v;
	for(auto u : adj[v])
	{
		if(u == par[v][0])
			continue;
		h[u] = h[v] + 1;
		par[u][0] = v;
		for(int i = 1; i < maxb; i++)
			par[u][i] = par[par[u][i - 1]][i - 1];
		set_dfs(u);
	}
	ft[v] = now;
}

bool is_par(int v , int u)
{
	return st[v] <= st[u] && st[u] <= ft[v];
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

void dfs(int v)
{
//	cout << v + 1 << endl;
	int x = 0;
	for(auto u : out[v])
	{
		if(W(v , u) == 1 && is[u] && is[v])
			res = 1e9;
		dfs(u);
		x += is[u];
	}
	if(is[v])
		res += x;
	else if(x > 1)
		res++;
	else if(x == 1)
		is[v] = 1;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	set_dfs(0);
	int q;
	cin >> q;
	while(q--)
	{
		int k;
		cin >> k;
		for(int i = 0; i < k; i++)
		{
			int v;
			cin >> v;
			v--;
			is[v] = 1;
			a[i] = st[v];
		}
		sort(a , a + k);

		int k1 = k;

		for(int i = 0; i < k; i++)
		{
			int v = rst[a[i]] , u = rst[a[i + 1]];
			int x = lca(v , u);
			tmpst[i] = a[i];
			tmpst[k1] = st[x];
			k1++;
		}
		k1--;
		sort(tmpst , tmpst + k1);
		k1 = unique(tmpst , tmpst + k1) - tmpst;
		stack<int> st;
		for(int i = 0; i < k1; i++)
		{
			while(!st.empty() && !is_par(st.top() , rst[tmpst[i]]))
				st.pop();
			if(!st.empty())
				out[st.top()].pb(rst[tmpst[i]]);
			st.push(rst[tmpst[i]]);
		}
		res = 0;
		dfs(rst[tmpst[0]]);
		for(int i = 0; i < k1; i++)
		{
			is[rst[tmpst[i]]] = 0;
			out[rst[tmpst[i]]].clear();
		}
		cout << (res >= n? -1 : res) << endl;
	}
}