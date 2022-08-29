#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bad[100500];
vector <int> g[100500];

vector <int> maxDists[100500];

int maxDistInSub[100500];
int n, m, d;

int dfs(int v, int par = -1)
{
	int md = -1;
	if (bad[v] == true)
		md = 0;
	for (int i = 0; i < g[v].size(); i++)
	{
		int nv = g[v][i];
		if (nv == par)
			continue;
		int nans = dfs(nv, v);
		if (nans == -1)
			continue;

		maxDists[v].push_back(nans);
		md = max(nans + 1, md);
	}
	sort(maxDists[v].begin(), maxDists[v].end() );
	reverse(maxDists[v].begin(), maxDists[v].end() );

	maxDistInSub[v] = md;
	return md;
}

int answer = 0;

void getAns(int v, int par = -1, int pmd = -1)
{
	int md = max(pmd, maxDistInSub[v] );
	if (md <= d)
		answer++;

	if (bad[v] )
		pmd = max(pmd, 0);

	for (int i = 0; i < g[v].size(); i++)
	{
		int nv = g[v][i];
		if (nv == par)
			continue;
		int downd = -1;
		if (pmd != -1)
			downd = max(downd, pmd + 1);
		if (maxDists[v].size() > 0 && maxDistInSub[nv] != maxDists[v][0] )
			downd = max(downd, maxDists[v][0] + 2);
		else if (maxDists[v].size() > 1)
			downd = max(downd, maxDists[v][1] + 2);

		getAns(nv, v, downd);
	}
}

int main()
{

	scanf("%d%d%d", &n, &m, &d);


	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		bad[x] = true;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0);

	getAns(0);


	printf("%d", answer);

	return 0;
}