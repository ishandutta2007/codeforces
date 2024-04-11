#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int a[maxn] , now , cnt;

vector<int> adj[maxn] , ver[maxn];

bool visited[maxn];

ll ans[maxn];

void dfs(int v)
{
	cnt++;
	visited[v] = 1;

	for(auto u : adj[v])
		if(a[u] % now == 0 && !visited[u])
			dfs(u);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i] , ver[a[i]].pb(i);

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	for(int i = maxn - 1; i > 0; i--)
	{
		now = i;

		ll res = 0;
		for(int j = i; j < maxn; j += i)
		{
			for(auto v : ver[j])
				if(!visited[v])
				{
					cnt = 0;
					dfs(v);
					res += 1LL * cnt * (cnt + 1) / 2;
				}

			ans[i] -= ans[j];
		}

		ans[i] += res;

		for(int j = i; j < maxn; j += i)
			for(auto v : ver[j])
				visited[v] = 0;
	}

	for(int i = 1; i < maxn; i++)
		if(ans[i])
			cout << i << " " << ans[i] << endl;

}