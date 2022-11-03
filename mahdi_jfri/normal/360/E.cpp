#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> adj[maxn] , adj2[maxn];

ll d[maxn] , l[maxn] , r[maxn] , w[maxn];

int par[maxn] , from[maxn] , to[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , k;
	cin >> n >> m >> k;

	int s1 , s2 , f;
	cin >> s1 >> s2 >> f;
	s1-- , s2-- , f--;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b >> w[i];
		a-- , b--;

		adj[a].pb(i);

		from[i] = a , to[i] = b;
	}

	for(int i = m; i < m + k; i++)
	{
		int a , b;
		cin >> a >> b >> l[i] >> r[i];
		a-- , b--;

		adj2[a].pb(i);

		from[i] = a , to[i] = b;
	}

	set<pair<ll , int> > st;

	memset(d , 63 , sizeof d);
	memset(par , -1 , sizeof par);

	par[s1] = s1;
	d[s1] = 0;
	st.insert({0 , s1});

	par[s2] = s2;
	d[s2] = 0;
	st.insert({0 , s2});

	while(!st.empty())
	{
		ll W = st.begin() -> first;
		int v = st.begin() -> second;
		st.erase(st.begin());

		if(W != d[v])
			continue;

		for(auto e : adj2[v])
		{
			if(par[v] == s1)
				w[e] = l[e];
			else
				w[e] = r[e];

			adj[v].pb(e);
		}

		for(auto e : adj[v])
		{
			int u = from[e] ^ to[e] ^ v;
			if(w[e] + W < d[u])
			{
				d[u] = w[e] + W;
				st.insert({d[u] , u});
				par[u] = par[v];
			}
		}
	}

	for(int i = 0; i < n; i++)
        adj2[i].clear();

    for(int i = 0; i < n; i++)
    {
        for(auto e : adj[i])
            adj2[from[e] ^ to[e] ^ i].pb(e);
        adj[i].clear();
    }

	memset(d , 63 , sizeof d);
	d[f] = 0;
	st.insert({0 , f});

	while(!st.empty())
	{
		ll W = st.begin() -> first;
		int v = st.begin() -> second;
		st.erase(st.begin());

		if(W != d[v])
			continue;

		for(auto e : adj2[v])
		{
			int u = from[e] ^ to[e] ^ v;

			if(w[e] + W < d[u])
			{
				d[u] = w[e] + W;
				st.insert({d[u] , u});
			}
		}
	}

	if(d[s1] > d[s2])
		return cout << "LOSE" << endl , 0;

	if(d[s1] == d[s2])
		cout << "DRAW" << endl;
	else
		cout << "WIN" << endl;

	for(int i = 0; i < k; i++)
    {
        if(w[i + m] == 0)
            w[i + m] = l[i + m];
        cout << w[i + m] << endl;
    }

}