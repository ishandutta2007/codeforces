#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int start[maxn] , m , ans[maxn];
vector<pair<int , int> > seg[maxn * 4];

int id = 1;
map<pair<int , int> , int> mp;

int par[maxn] , sz[maxn];
vector<pair<pair<int , int> , bool> > history;
bool col[maxn] , is;

pair<int , bool> f(int v)
{
	bool shit = 0;
	while(par[v] != -1)
	{
		shit ^= col[v];
		v = par[v];
	}

	return make_pair(v , shit ^ col[v]);
}

void unite(int v , int u)
{
	auto a = f(v) , b = f(u);

	if(a.first == b.first)
	{
		history.pb({{a.first , b.first} , is});
		if(a.second == b.second)
			is = 0;
		return;
	}

	if(sz[a.first] > sz[b.first])
		swap(a , b);

	par[a.first] = b.first;
	sz[b.first] += sz[a.first];

	if((a.second ^ col[b.first]) == b.second)
		col[a.first] ^= 1;

	history.pb({{a.first , b.first} , is});
}

void undo()
{
	auto shit = history.back();
	history.pop_back();

	int a = shit.first.first , b = shit.first.second;

	is = shit.second;
	if(a == b)
		return;

	par[a] = -1;
	sz[b] -= sz[a];
}

void add(int l , int r , int u , int w , int s = 0 , int e = maxn , int v = 1)
{
	if(l <= s && e <= r)
	{
		seg[v].pb(make_pair(u , w));
		return;
	}
	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;

	add(l , r , u , w , s , m , 2 * v);
	add(l , r , u , w , m , e , 2 * v + 1);
}

void dfs(int s = 0 , int e = maxn , int v = 1)
{
	for(auto E : seg[v])
		unite(E.first , E.second);

	if(e - s < 2)
	{
		cout << (is? "YES" : "NO") << endl;

		if(s == m - 1)
			exit(0);

		for(auto E : seg[v])
			undo();

		return;
	}

	int m = (s + e) / 2;
	
	dfs(s , m , 2 * v);
	dfs(m , e , 2 * v + 1);

	for(auto E : seg[v])
		undo();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(par , -1 , sizeof par);
	fill(sz , sz + maxn , 1);

	is = 1;

	int n;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		if(a > b)
			swap(a , b);

		auto p = make_pair(a , b);
		int tmp = mp[p];

		if(tmp)
		{
			add(start[tmp] , i , a , b);
			mp[p] = 0;
		}
		else
		{
			start[id] = i;
			mp[p] = id;
			id++;
		}
	}

	for(auto x : mp)
		if(x.second)
			add(start[x.second] , m , x.first.first , x.first.second);

	dfs();

	for(int i = 0; i < m; i++)
		cout << ((ans[i])? "YES" : "NO") << endl;

}