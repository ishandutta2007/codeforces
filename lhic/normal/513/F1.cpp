#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 100ll;

const int MAXN = 3000;

int fl;

int dd[23][23];
int arr[23][23];


int n, m, fm, ml;
vector<tuple<int, int, ll> > bb;
vector<tuple<int, int, ll> > gg;

deque<int> dq;

int t, s;


struct edge
{
	ll c, w, f;
	int a, b;
};

ll nd;

int was[MAXN];

vector<edge> ed;

vector<int> eds[MAXN];


void add_edge(int a, int b, int c, ll w)
{
	edge x;
	x.a = a;
	x.b = b;
	x.c = c;
	x.w = w;
	x.f = 0;
	eds[a].push_back(ed.size());
	ed.push_back(x);
	swap(x.a, x.b);
	x.c = 0;
	x.w = -x.w;
	eds[b].push_back(ed.size());
	ed.push_back(x);
}


int tm = 0;
int dfs(int v, ll x)
{
	if (v == t)
		return 1;
	was[v] = tm;
	for (int i = 0; i < (int)eds[v].size(); ++i)
	{
		int q = eds[v][i];
		int u = ed[q].b;
		if (was[u] < tm && ed[q].w <= x && ed[q].c > ed[q].f)
		{
			if (dfs(u, x))
			{
				++ed[q].f;
				--ed[q ^ 1].f;
				return 1;
			}
		}
	}
	return 0;
}


bool flow(ll x)
{
	for (int i = 0; i < (int)ed.size(); ++i)
		ed[i].f = 0;
	int ans = 0;
	while (true)
	{
		++tm;
		int xx = dfs(s, x);
		if (!xx)
			break;
		ans += xx;
	}
	if (ans < nd)
		return 0;
	else
		return 1;
}



int main()
{
//	freopen("input.txt", "r", stdin);
	cin >> n >> m >> ml >> fm;
	if (ml + 1 == fm)
		fl = 1;
	if (fm + 1 == ml)
		fl = 2;
	if (!fl)
	{
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			char c;
			scanf(" %c", &c);
			if (c == '.')
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}

	int a, b;
	ll c;
	scanf("%d%d%I64d", &a, &b, &c);
	--a;
	--b;
	if (fl == 1)
		bb.push_back(make_tuple(a, b, c));
	else
		gg.push_back(make_tuple(a, b, c));
	for (int i = 0; i < ml; ++i)
	{
		scanf("%d%d%I64d", &a, &b, &c);
		--a;
		--b;
		bb.push_back(make_tuple(a, b, c));
	}
	for (int i = 0; i < fm; ++i)
	{
		scanf("%d%d%I64d", &a, &b, &c);
		--a;
		--b;
		gg.push_back(make_tuple(a, b, c));
	}

	s = ml + fm + 2 * n * m + 1;
	t = s + 1;

	for (int i = 0; i < (int)bb.size(); ++i)
		add_edge(s, i, 1, 0);
	for (int i = 0; i < (int)gg.size(); ++i)
		add_edge(i + (int)bb.size(), t, 1, 0);

	for (int i = 0; i < (int)bb.size(); ++i)
	{
		for (int i1 = 0; i1 < n; ++i1)
			for (int j1 = 0; j1 < m; ++j1)
				dd[i1][j1] = 2280;
		int x = get<0>(bb[i]);
		int y = get<1>(bb[i]);
		dd[x][y] = 0;
		queue<pair<int, int> > qu;
		qu.push({x, y});
		while (!qu.empty())
		{
			pair<int, int> tmp = qu.front();
			qu.pop();
			int xx = tmp.first;
			int yy = tmp.second;
			for (int dx = -1; dx < 2; ++dx)
				for (int dy = -1; dy < 2; ++dy)
				{
					if (abs(dx) + abs(dy) != 1 || xx + dx < 0 || xx + dx >= n || yy + dy < 0 || yy + dy >= m || !arr[xx + dx][yy + dy])
						continue;
					if (dd[xx + dx][yy + dy] > dd[xx][yy] + 1)
					{
						dd[xx + dx][yy + dy] = dd[xx][yy] + 1;
						qu.push({xx + dx, yy + dy});
					}
				}
		}
		for (int i1 = 0; i1 < n; ++i1)
			for (int j1 = 0; j1 < m; ++j1)
				if (dd[i1][j1] < 2280)
					add_edge(i, ml + fm + 1 + i1 * m + j1, 1, dd[i1][j1] * get<2>(bb[i]));
	}
	for (int i = 0; i < (int)gg.size(); ++i)
	{
		for (int i1 = 0; i1 < n; ++i1)
			for (int j1 = 0; j1 < m; ++j1)
				dd[i1][j1] = 2280;
		int x = get<0>(gg[i]);
		int y = get<1>(gg[i]);
		dd[x][y] = 0;
		queue<pair<int, int> > qu;
		qu.push({x, y});
		while (!qu.empty())
		{
			pair<int, int> tmp = qu.front();
			qu.pop();
			int xx = tmp.first;
			int yy = tmp.second;
			for (int dx = -1; dx < 2; ++dx)
				for (int dy = -1; dy < 2; ++dy)
				{
					if (abs(dx) + abs(dy) != 1 || xx + dx < 0 || xx + dx >= n || yy + dy < 0 || yy + dy >= m || !arr[xx + dx][yy + dy])
						continue;
					if (dd[xx + dx][yy + dy] > dd[xx][yy] + 1)
					{
						dd[xx + dx][yy + dy] = dd[xx][yy] + 1;
						qu.push({xx + dx, yy + dy});
					}
				}
		}
		for (int i1 = 0; i1 < n; ++i1)
			for (int j1 = 0; j1 < m; ++j1)
				if (dd[i1][j1] < 2280)
					add_edge(ml + fm + 1 + n * m + i1 * m + j1, i + (int)bb.size(), 1, dd[i1][j1] * get<2>(gg[i]));
	}

	for (int i = 0; i < n * m; ++i)
		add_edge(ml + fm + 1 + i, ml + fm + 1 + n * m + i, 1, 0);
	

	nd = max(fm, ml);


	ll l = -1;
	ll r = 500ll * 1000000000;
	while (r - l > 1)
	{
		ll x = (l + r) / 2;
	//	cout << l << " " << r << " " << x << "\n";
		if (flow(x))
			r = x;
		else
			l = x;
	}
	if (r == 500ll * 1000000000)
		cout << -1;
	else
		cout << r;



	return 0;
}