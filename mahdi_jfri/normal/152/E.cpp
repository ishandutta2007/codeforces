#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 2e2 + 20;
const int maxm = maxn * 4;
const int maxk = 8;

vector<int> adj[maxn] , marked;

int n , m , a[maxn] , dp[maxn][1 << maxk];

bitset<maxn> ans[maxn][1 << maxk];

int get(int x , int y)
{
	return x * m + y;	
}

int main()
{
	memset(dp , 63 , sizeof dp);
	int k;
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			int k = get(i , j);
			cin >> a[k];
			if(i)
				adj[k].pb(get(i - 1 , j));
			if(i + 1 < n)
				adj[k].pb(get(i + 1 , j));
			if(j)
				adj[k].pb(get(i , j - 1));
			if(j + 1 < m)
				adj[k].pb(get(i , j + 1));
		}
	for(int i = 0; i < k; i++)
	{
		int x , y;
		cin >> x >> y;
		x-- , y--;

		int k1 = get(x , y);
		marked.pb(k1);

		dp[k1][1 << i] = a[k1];
		ans[k1][1 << i][k1] = 1;
	}

	int hlp = (1 << k);

	for(int mask = 1; mask < hlp; mask++)
	{
		set<pair<int , int> > st;
		for(int i = 0; i < n * m; i++)
		{
			for(int submask = (mask - 1) & mask; submask > 0; submask = (submask - 1) & mask)
			{
				int k = dp[i][submask] + dp[i][mask ^ submask] - a[i];
				if(dp[i][mask] > k)
				{
					dp[i][mask] = k;
					ans[i][mask] = ans[i][submask] | ans[i][mask ^ submask];
				}
			}
			st.insert({dp[i][mask] , i});
		}

		while(!st.empty())
		{
			int v = st.begin() -> second;
			int W = st.begin() -> first;

			st.erase(st.begin());
			if(W != dp[v][mask])
				continue;

			for(auto u : adj[v])
				if(dp[u][mask] > W + a[u])
				{
					dp[u][mask] = W + a[u];
					ans[u][mask] = ans[v][mask];
					ans[u][mask][u] = 1;
					st.insert({dp[u][mask] , u});
				}
		}
	}

	int res = dp[marked.back()][hlp - 1];

	cout << res << endl;

	for(int i = 0; i < n; i++ , cout << endl)
		for(int j = 0; j < m; j++)
		{
			if(ans[marked.back()][hlp - 1][get(i , j)])
				cout << 'X';
			else
				cout << '.';
		}
}