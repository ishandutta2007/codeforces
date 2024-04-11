#include <iostream>
#include <vector>
using namespace std;


const int N = 1100100;
//const int N = 100;

vector <int>  grev[N];

vector <int> qu;
vector <int> quNext;

int dist[N];
int st[N];

vector <pair<int, int> > E;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		E.push_back(make_pair(a, b) );
	}
	int s, t;
	scanf("%d%d", &s, &t);
	s--;
	t--;


	for (int i = 0; i < E.size(); i++)
	{
		int a = E[i].first;
		int b = E[i].second;
		if (a == t)
			continue;
		grev[b].push_back(a);
		st[a]++;
	}
	memset(dist, -1, sizeof dist);

	int d = 0;
	dist[t] = 0;
	qu.push_back(t);

	while (true)
	{
		if (qu.size() == 0)
		{
			d++;
			qu.swap(quNext);
			if (qu.size() == 0)
				break;
			continue;
		}
		int cur = qu.back();
		qu.pop_back();
		if (dist[cur] != d)
			continue;
		if (cur == s)
		{
			printf("%d\n", dist[s] );
			return 0;
		}

		for (int i = 0; i < grev[cur].size(); i++)
		{
			int v = grev[cur][i];
			st[v]--;
			if (st[v] == 0 && dist[v] != d)
			{
				dist[v] = d;
				qu.push_back(v);
				continue;
			}
			if (dist[v] != -1)
				continue;
			dist[v] = d + 1;
			quNext.push_back(v);
		}
	}
	printf("-1");

	return 0;
}