#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;

vector<int> adj[maxn] , ver[maxn];
vector<pair<int , int> > mh[maxn];

int a[maxn] , b[maxn];

int LazyAdd[maxn * 4] , mn[maxn * 4];

inline void handle(int v)
{
	sort(mh[v].begin() , mh[v].end());

	while((int)mh[v].size() > 2)
		mh[v].pop_back();
}

inline void dfs(int v , int p = -1)
{
	mh[v].pb({a[v] , v});
	handle(v);

	if((int)mh[v].size() == 1 || mh[v][0].first != mh[v][1].first)
		ver[mh[v][0].second].pb(v);

	for(auto u : adj[v])
		if(u != p)
		{
			mh[u] = mh[v];
			dfs(u , v);
		}
}

vector<int> cmp;

inline int Id(int x)
{
	return upper_bound(cmp.begin() , cmp.end() , x) - cmp.begin() - 1;
}

inline void add(int r , int val , int s , int e , int v)
{
	if(e <= r + 1)
	{
		LazyAdd[v] += val;
		mn[v] += val;
		return;
	}
	if(r + 1 <= s)
		return;

	int m = (s + e) / 2;

	add(r , val , s , m , 2 * v);
	add(r , val , m , e , 2 * v + 1);

	mn[v] = min(mn[2 * v] , mn[2 * v + 1]) + LazyAdd[v];
}

bool check(int v , int x)
{
	for(auto u : ver[v])
	{
		add(Id(mh[u][0].first) , -1 , 0 , cmp.size() , 1);
		add(Id(min(mh[u][1].first , x)) , 1 , 0 , cmp.size() , 1);
	}

	bool f = (mn[1] >= 0);

	for(auto u : ver[v])
	{
		add(Id(mh[u][0].first) , 1 , 0 , cmp.size() , 1);
		add(Id(min(mh[u][1].first , x)) , -1 , 0 , cmp.size() , 1);
	}

	return f;
}

int main()
{
	int n;
	scanf("%d" , &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	int k;
	scanf("%d" ,&k);

	for(int i = 0; i < k; i++)
		scanf("%d", &b[i]) , cmp.pb(b[i]);

	dfs(0);
	mh[0].pb({2e9 , -1});

	sort(cmp.begin() , cmp.end());
	cmp.resize(unique(cmp.begin() , cmp.end()) - cmp.begin());

	for(int i = 0; i < k; i++)
		add(Id(b[i]) , -1 , 0 , cmp.size() , 1);
	for(int i = 0; i < n; i++)
		add(Id(mh[i][0].first) ,  1 , 0 , cmp.size() , 1);

	if(mn[1] >= 0)
		return cout << 0 << endl , 0;

	int res = 2e9;

	for(int v = 0; v < n; v++)
	{
		int l = a[v] , r = 1e9 + 10;

		if(!check(v , r))
			continue;

		while(r - l > 1)
		{
			int m = (l + r) / 2;
			if(check(v , m))
				r = m;
			else
				l = m;
		}

		res = min(res , r - a[v]);
	}

	if(res >= 1e9)
		res = -1;

	cout << res << endl;
}