#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , tp , best , num[50];
bool a[50][50];
char na[50];
string s;
vector<int> v;
map<string,int> nap;

bool dfs(int *adj , int total , int cnt)
{
	int t[50] , i , j , k;
	if (!total)
	{
		if (cnt > best)
		{
			best = cnt;
			return true;
		}
		return false;
	}
	for (i = 0 ; i < total ; i++)
	{
		if (cnt+total-i <= best) return false;
		if (cnt+num[adj[i]] <= best) return false;
		k = 0;
		for (j = i+1 ; j < total ; j++)
			if (a[adj[i]][adj[j]]) t[k++] = adj[j];
		if (dfs(t,k,cnt+1)) return true;
	}
	return false;
}

int maximumclique()
{
	int adj[50] , i , j , k;
	best = 0;
	for(i = m ; i >= 1 ; i--)
	{
		k = 0;
		for (j = i+1 ; j <= m ; j++)
			if (a[i][j]) adj[k++] = j;
		dfs(adj,k,1);
		num[i] = best;
	}
	return best;
}

void handle()
{
	int f[50] , sz = v.size() , i , j;
	memset(f,0,sizeof(f));
	for (i = 0 ; i < sz ; i++)
		f[v[i]] = 1;
	v.clear();
	for (i = 1 ; i <= m ; i++)
		if (f[i]) v.push_back(i);
	sz = v.size();
	for (i = 0 ; i < sz ; i++)
	{
		for (j = 0 ; j < sz ; j++)
		{
			a[v[i]][v[j]] = true;
			a[v[j]][v[i]] = true;
		}
	}
	v.clear();
}

int main()
{
	int i , j , k;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&k);
		if (k == 1)
		{
			if (v.size() > 0) handle();
		}
		else
		{
			scanf("%s",na);
			s = na;
			if (!nap[s]) nap[s] = ++tp;
			v.push_back(nap[s]);
		}
	}
	if (v.size() > 0) handle();
	for (i = 1 ; i <= m ; i++)
		for (j = 1 ; j <= m ; j++)
			a[i][j] = !a[i][j];
	cout << maximumclique() << "\n";
	return 0;
}