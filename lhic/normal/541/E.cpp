#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 200001;

vector <int> e[MAXN];
int d[MAXN];
int q[MAXN], qb = 0, qe = 0;
int g[MAXN];
int ans[MAXN];

int main()
{
	int n, m;
	cin >> n >> m;	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) g[i] = -1;
	int an = 0, gc = 0;
	for (int st = 1; st <= n; st++)
	{
		for (int i = 1; i <= n; i++) d[i] = -1;
		if (g[st] == -1)
		{
			ans[gc] = 0;
			g[st] = gc++;
		}
		qb = 0, qe = 1;
		q[0] = st;
		d[st] = 0;
		while (qb < qe)
		{
			int v = q[qb++];
			g[v] = g[st];
			ans[g[v]] = max(ans[g[v]], d[v]);
			for (int i = 0; i < e[v].size();  i++)
			{
				int u = e[v][i];
				if (d[u] == -1)
				{
					d[u] = d[v] + 1;
					q[qe++] = u;
				}
				else if (d[u] == d[v])
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	for (int i = 0; i< gc; i++) an += ans[i];
	cout << an << endl;
	return 0;
}