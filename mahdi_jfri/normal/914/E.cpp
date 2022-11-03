#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int ll

const int maxn = 2e5 + 20;
const int maxm = 2e6 + 20;

vector<int> adj[maxn];

int a[maxn] , sz[maxn] , ans[maxn] , d[maxn] , t[maxn] , cnt[maxm] , x;

bool picked[maxn];

void plant(int v , int p = -1)
{
	sz[v] = 1;
	cnt[d[v]]++;
	for(auto u : adj[v])
		if(!picked[u] && u != p)
		{
			d[u] = d[v] ^ a[u];
			plant(u , v);
			sz[v] += sz[u];
		}
}

void unplant(int v , int p = -1)
{
	cnt[d[v]]--;
	for(auto u : adj[v])
		if(!picked[u] && u != p)
			unplant(u , v);
}

int get_centroid(int v , int root , int p = -1)
{
	for(auto u : adj[v])
		if(!picked[u] && u != p && (2 * sz[u] > sz[root]))
			return get_centroid(u , root , v);
	return v;
}

void dfs(int v , int cnt1 , int p)
{
	t[v] = cnt[d[v] ^ a[cnt1]];
	for(int i = 0; i < 22; i++)
		if((d[v] ^ a[cnt1] ^ (1 << i)) < maxm)
			t[v] += cnt[d[v] ^ a[cnt1] ^ (1 << i)];
	if(__builtin_popcount(d[v]) < 2)
		t[v]++;
	for(auto u : adj[v])
		if(!picked[u] && u != p)
			dfs(u , cnt1 , v) , t[v] += t[u];
	ans[v] += t[v];
}

void centroid_dfs(int v)
{
	plant(v);
	unplant(v);
	v = get_centroid(v , v);
	d[v] = a[v];
	plant(v);
	cnt[d[v]]--;
	x = 0;
	for(auto u : adj[v])
		if(!picked[u])
		{
			unplant(u , v);
			dfs(u , v , v);
			x += t[u];
			plant(u , v);
		}
	cnt[d[v]]++;
	for(int i = 0; (1 << i) < maxm; i++)
		x += cnt[(1 << i)];
	x += cnt[0];
	ans[v] += x / 2 + 1;
	unplant(v);
	picked[v] = 1;
	for(auto u : adj[v])
		if(!picked[u])
			centroid_dfs(u);
}

int32_t main()
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
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	string s;
	cin >> s;
	for(int i = 0; i < n; i++)
		a[i] = (1 << (s[i] - 'a'));

	centroid_dfs(0);

	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
}