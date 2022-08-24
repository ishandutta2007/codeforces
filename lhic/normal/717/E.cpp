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
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 200001;

int a[MAXN];
vector <int> e[MAXN];


void dfs(int v, int p)
{
	for (int i = 0; i < e[v].size(); i++)
	{
		int u = e[v][i];
		if (u == p) continue;
		a[u] = -a[u];
		cout << u << " ";
		dfs(u, v);
		cout << v << " ";
		a[v] = -a[v];
		if (a[u] == -1)
		{
			cout << u << " " << v << " ";
			a[v] = -a[v];
			a[u] = -a[u];
		}
	}
}




int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout << "1 ";
	dfs(1, 1);
	if (a[1] == -1) cout << e[1][0] << " " << 1 << " " << e[1][0] << endl;
	else cout << endl;
	return 0;
}