#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
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
typedef pair <int,int> II;
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , f[maxn] , t[maxn] , h , s[maxn];
vector<int> v[maxn];

void dfs(int x , int y)
{
	f[x] = y;
	for (int i = 0 ; i < v[x].size() ; i++)
	{
		if (y != v[x][i]) dfs(v[x][i],x);
	}
}

bool check()
{
	if (t[1] != 1) return false;
	h = 1;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = h+1 ; j <= h+v[t[i]].size()-1 ; j++)
		{
			if (f[t[j]] != t[i]) return false;
		}
		h = h+v[t[i]].size()-1;
	}
	return true;
}

int main()
{
	int i , x , y;
	cin >> n;
	v[1].push_back(0);
	for (i = 1 ; i < n ; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&t[i]);
	}
	dfs(1,0);
	if (check()) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}