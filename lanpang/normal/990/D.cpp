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
const int maxn = 1e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a , b , c[maxn][maxn];

void jisuan(int x)
{
	for (int i = 1 ; i <= n-x ; i++)
	{
		c[i][i+1] = 1;
		c[i+1][i] = 1;
	}
}

void gao()
{
	int i , j;
	cout << "YES\n";
	if (a == 1)
	{
		jisuan(b);
		for (i = 1 ; i <= n ; i++)
		{
			for (j = 1 ; j <= n ; j++)
			{
				if (i != j) c[i][j] = 1-c[i][j];
			}
		}
	}
	else jisuan(a);
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= n ; j++)
		{
			printf("%d",c[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	cin >> n >> a >> b;
	if (a == 1 || b == 1)
	{
		if (n == 2 || n == 3)
		{
			if (n == 2)
			{
				if (max(a,b) == 2) gao();
				else cout << "NO\n";
			}
			else
			{
				if (max(a,b) >= 2) gao();
				else cout << "NO\n";
			}
		}
		else gao();
	}
	else cout << "NO\n";
	return 0;
}