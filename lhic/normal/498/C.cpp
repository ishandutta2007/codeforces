#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <bitset>


using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 5000;

vector<int> v[2];
vector<int> vv[2];

int arr[MAXN];

vector<int> eds[MAXN];

int ed[MAXN][MAXN];

int n, m;

int go[MAXN];
int was[MAXN];


int dfs(int v)
{
	was[v] = 1;
	for (int i = 0; i < (int)eds[v].size(); ++i)
	{
		int u = eds[v][i];
		if (go[u] == -1)
		{
			go[u] = v;
			return 1;
		}
	}
	
	for (int i = 0; i < (int)eds[v].size(); ++i)
	{
		int u = eds[v][i];
		
		if (!was[go[u]])
			if (dfs(go[u]))
			{
				go[u] = v;
				return 1;
			}
	}
	return 0;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		ed[a][b] = 1;
		ed[b][a] = 1;
	}
	
	for (int i = 0; i < n; ++i)
	{
		int k = arr[i];
		for (int j = 2; j * j <= k; ++j)
		{
			while (k % j == 0)
			{
				k /= j;
				v[i % 2].push_back(j);
				vv[i % 2].push_back(i);
			}
		}
		if (k != 1)
		{
			v[i % 2].push_back(k);
			vv[i % 2].push_back(i);
		}	
	}
	
	for (int i = 0; i < v[0].size(); ++i)
		for (int j = 0; j < v[1].size(); ++j)
		{
			if (ed[vv[0][i]][vv[1][j]] && v[0][i] == v[1][j])
				eds[i].push_back(j);
		}
	
	for (int i = 0; i < (int)v[1].size(); ++i)
		go[i] = -1;
	
	
	int cnt = 0;
	
	for (int i = 0; i < (int)v[0].size(); ++i)
	{
		memset(was, 0, sizeof(was[0]) * (int)v[0].size());
		cnt += dfs(i);
	}
	
	cout << cnt;
	
	
	
	return 0;
}