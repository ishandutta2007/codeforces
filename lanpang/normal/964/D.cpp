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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

vector <int> a[maxn];
int num[maxn] , n , b[maxn] , f[maxn];

void dfs1(int x , int fa)
{
	f[x] = 1;
	printf("%d\n",x);
	for (int i = 0 ; i < a[x].size() ; i++)
	{
		if (f[a[x][i]] == 0 && a[x][i] != fa) dfs1(a[x][i],x);
	}
	return;
}

int dfs(int x , int fa)
{
	if (a[x].size() == 1 && fa != 0) return 1;
	int j = 1 , k = 0 , p;
	for (int i = 0 ; i < a[x].size() ; i++)
	{
		if (a[x][i] != fa) 
		{
			p = dfs(a[x][i],x);
			j += p;
			if (p > 0 && p%2 == 0) k = 1;
		}
	}
	if (b[x]%2 == 0 && k == 0) 
	{
		b[fa]--;
		dfs1(x,fa);
		return 0;
	}
	return j;
}

int main()
{
	int i , j;
	scanf("%d",&n);
	for (i = 1 ; i <= n ; i++)
	{
		int x , y;
		x = i;
		scanf("%d",&y);
		if (!y) continue;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (i = 1 ; i <= n ; i++) b[i] = a[i].size();
	if (n%2 == 0)
	{ 
		cout << "NO\n";
		return 0;
	} 
	cout << "YES\n";
	dfs(1,0);
}