#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;
const int maxk = 52;

int par[maxn][maxk] , sz[maxn][maxk] , pos[maxn];

bool val[maxn][maxk];

vector<pair<pair<int , int> , pair<int , bool> > > history;

int from[maxn] , to[maxn] , e[maxn] , c[maxn];

vector<int> times[maxn] , color[maxn] , color_edgeh[maxn];

vector<pair<int , int> > obj[maxn * 4];

inline pair<int , bool> get(int v , int k)
{
	bool x = 0;
	while(par[v][k] != -1)
	{
		x ^= val[v][k];
		v = par[v][k];
	}
	x ^= val[v][k];

	return make_pair(v , x);
}

inline void merge(int e , int k)
{
	int v = from[e] , u = to[e];
	pair<int , bool> x = get(v , k);
	pair<int , bool> y = get(u , k);

	color_edgeh[e].pb(k);

	if(x.first == y.first)
	{
		history.pb(make_pair(make_pair(-1 , 0) , make_pair(0 , 0)));
		return;
	}

	if(sz[y.first][k] > sz[x.first][k])
		swap(x , y);

	bool tmp = 0;
	par[y.first][k] = x.first;
	sz[x.first][k] += sz[y.first][k];

	if(y.second == x.second)
		val[y.first][k] ^= 1 , tmp = 1;

	history.pb(make_pair(make_pair(y.first , x.first) , make_pair(k , tmp)));
}

inline bool can(int v , int u , int k)
{
	auto x = get(v , k);
	auto y = get(u , k);

	return (x.first != y.first) || (x.second != y.second) || !k;
}

inline void undo()
{
	auto tmp = history.back();
	int v = tmp.first.first , u = tmp.first.second , k = tmp.second.first , t = tmp.second.second;
	history.pop_back();

	if(v == -1)
		return;

	sz[u][k] -= sz[v][k];
	par[v][k] = -1;

	val[tmp.first.first][k] ^= t;
}

inline void add(int l , int r , pair<int , int> val , int s = 0 , int e = maxn , int v = 1)
{
	if(l <= s && e <= r)
	{
		obj[v].pb(val);
		return;
	}
	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;

	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);
}

inline void dfs(int s = 0 , int E = maxn , int v = 1)
{
	for(auto tmp : obj[v])
	{
		int edge = tmp.first , C = color[tmp.first][tmp.second];
		merge(edge , C);
	}

	if(E - s < 2)
	{
		if(s + 1 < maxn && c[s + 1])
		{
			int edge = e[s + 1];
			if(!can(from[edge] , to[edge] , c[s + 1]))
			{
				int k = pos[s + 1];

				color[edge][k] = color_edgeh[edge].back();
				printf("NO\n");
			}
			else
				printf("YES\n");
		}
		else
			exit(0);
		for(auto tmp : obj[v])
		{
			int edge = tmp.first;
			color_edgeh[edge].pop_back();
			undo();
		}
		return;
	}

	int m = (s + E) / 2;

	dfs(s , m , 2 * v);
	dfs(m , E , 2 * v + 1);

	reverse(obj[v].begin() , obj[v].end());

	for(auto tmp : obj[v])
	{
		int edge = tmp.first;
		color_edgeh[edge].pop_back();
		undo();
	}

}


int main()
{
	history.reserve(maxn * 4);
	memset(par , -1 , sizeof par);

	int n , m , q , k;
	cin >> n >> m >> k >> q;

	for(int i = 0; i < maxn; i++)
		color_edgeh[i].pb(0);

	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &from[i], &to[i]);

		from[i]-- , to[i]--;
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j <= k; j++)
			sz[i][j] = 1;

	for(int i = 0; i < q; i++)
	{
		scanf("%d%d", &e[i], &c[i]);
		e[i]--;

		pos[i] = times[e[i]].size();
		times[e[i]].pb(i);
		color[e[i]].pb(c[i]);
	}

	for(int i = 0; i < m; i++)
		for(int j = 0; j < (int)times[i].size(); j++)
		{
			int nxt = (j + 1 < (int)times[i].size())? times[i][j + 1] : maxn;

			add(times[i][j] , nxt , make_pair(i , j));
		}

	printf("YES\n");
	dfs();
}