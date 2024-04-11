#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


const int maxn = 1e6 + 100;
int used[maxn];
vector <int> g[maxn];
int SD[maxn];
int FD[maxn];

vector <pair<int, int> > bst[maxn]; 

int dfs1(int v, int par, int leader)
{
	used[v] = leader;
	bst[v].push_back(make_pair(0, v) );
	bst[v].push_back(make_pair(0, v) );
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int nv = g[v][i];
		if (nv == par)
			continue;
		bst[v].push_back(make_pair(dfs1(nv, v, leader) + 1, nv) );
		sort(bst[v].begin(), bst[v].end() );
		reverse(bst[v].begin(), bst[v].end() );
		while (bst[v].size() > 2)
			bst[v].pop_back();
	}
	return bst[v][0].first;
}

int fd;
int sd;

void dfs2(int v, int par, pair <int, int> up)
{
	bst[v].push_back(up);
	sort(bst[v].begin(), bst[v].end() );
	reverse(bst[v].begin(), bst[v].end() );
	while (bst[v].size() > 2)
		bst[v].pop_back();
	int _fd = bst[v][0].first;
	int _sd = bst[v][1].first;
	if (_fd - _sd <= 1 && make_pair(_fd, _sd) >= make_pair(fd, sd) )
	{
		fd = _fd;
		sd = _sd;
	}
	
//	fprintf(stderr, "v = %d, fd = %d, sd = %d\n", v, _fd, _sd);
	
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int nv = g[v][i];
		if (nv == par)
			continue;
		if (bst[v][0].second != nv)
			dfs2(nv, v, make_pair(_fd + 1, v) );
		else
			dfs2(nv, v, make_pair(_sd + 1, v) );
	}
}


int getP(int v)
{
	if (used[v] == v)
		return v;
	return used[v] = getP(used[v] );
}
void uni(int a, int b)
{
	a = getP(a);
	b = getP(b);
	if (a == b)
		return;
	if (rand() & 1)
		swap(a, b);
	used[b] = a;
	if (FD[a] > FD[b] )
	{
		SD[a] = max(SD[a], FD[b] + 1);
		return;
	}
	if (FD[a] < FD[b] )
	{
		SD[a] = max(SD[b], FD[a] + 1);
		FD[a] = FD[b];
		return;
	}
	SD[a] = FD[a];
	FD[a]++;;
	
}




int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(used, -1, sizeof used);
	for (int i = 0; i < n; i++)
	{
		if (used[i] != -1)
			continue;
		dfs1(i, -1, i);
		sd = -1;
		fd = -1;
		dfs2(i, -1, make_pair(-1, -1) );
		SD[i] = sd;
		FD[i] = fd;
	}
	for (int i = 0; i < q; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int v;
			scanf("%d", &v);
			v--;
			v = getP(v);
			printf("%d\n", FD[v] + SD[v] );
		}
		else
		{
			int a, b;
			scanf("%d%d", &a, &b);
			a--;
			b--;
			uni(a, b);
//			int x = getP(a);
//			fprintf(stderr, "x = %d, FD = %d, SD = %d\n", x, FD[x], SD[x] );
		}
	}


	return 0;
}