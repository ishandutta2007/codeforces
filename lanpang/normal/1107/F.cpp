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

int n;
LL a[510][510];
int p[510];
LL q1[510];
LL q2[510];
int f1[510];
int f2[510];
LL g[510];

bool dfs(int x)
{
	int i;
	LL gap;
	f1[x] = 1;
	for (i = 1 ; i <= n ; i++)
	{
		if (f2[i] == 0)
		{
			gap = q1[x]+q2[i]-a[x][i];
			if (gap == 0)
			{
				f2[i] = 1;
				if (p[i] == 0 || dfs(p[i]))
				{
					p[i] = x;
					return true;
				}	
			}
			else g[i] = min(g[i],gap);
		}
	}	
	return false;
}

LL km()
{
	int i , j;
	LL k , ans;
	for (i = 1 ; i <= n ; i++)
	{
		p[i] = 0;
		q2[i] = 0;
	}
	for (i = 1 ; i <= n ; i++)
	{
		q1[i] = a[i][1];
		for (j = 2 ; j <= n ; j++)
			q1[i] = max(q1[i],a[i][j]);
	}
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= n ; j++)
			g[j] = mod*mod;
		while (1)
		{
			for (j = 1 ; j <= n ; j++)
			{
				f1[j] = 0;
				f2[j] = 0;
			}
			if (dfs(i)) break;
			k = mod*mod;
			for (j = 1 ; j <= n ; j++)
				if (f2[j] == 0) k = min(k,g[j]);
			for (j = 1 ; j <= n ; j++)
			{
				if (f1[j]) q1[j] -= k;
				if (f2[j]) q2[j] += k;
				else g[j] -= k;
			}
		}
	}
	ans = 0;
	for (i = 1 ; i <= n ; i++)
		ans += a[p[i]][i];
	return ans;
}

int main()
{
	int i , j;
	LL a1 , b1 , c1;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a1 >> b1 >> c1;
		for (j = 1 ; j <= n ; j++)
			a[i][j] = max(0LL,a1-b1*min((LL)j-1,c1));
	}
	cout << km() << "\n";
	return 0;
}