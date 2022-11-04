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
const LL mod = 1e9+7;

int n , b[maxn] , c[maxn] , s;
LL ans , a[2][10000010] , p[2];
vector<int> v[maxn];

void dfs(int x)
{
	if (v[x].size() == 0)
	{
		c[x] = 1;
		return;
	}
	for (int i = 0 ; i < v[x].size() ; i++)
		dfs(v[x][i]);
	c[x] = 1-c[v[x][0]];
}

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&b[i]);
	for (i = 2 ; i <= n ; i++)
	{
		scanf("%d",&j);
		v[j].push_back(i);
	}
	dfs(1);
	for (i = 1 ; i <= n ; i++)
	{
		a[c[i]%2][b[i]]++;
		p[c[i]%2]++;
		if (c[i]%2) s ^= b[i];
	}
	if (!s)
	{
		ans = (p[0]*(p[0]-1))/2+(p[1]*(p[1]-1))/2;
		for (i = 1 ; i <= 10000000 ; i++)
			ans += a[0][i]*a[1][i];
	}
	else
	{
		for (i = 1 ; i <= 10000000 ; i++)
			if ((i^s) <= 10000000) ans += a[0][i]*a[1][(i^s)];
	}
	cout << ans << "\n";
	return 0;
}