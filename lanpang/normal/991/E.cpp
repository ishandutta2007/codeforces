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
const int maxn = 20;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL c[maxn][maxn];
void createzuheshu() 
{
	c[0][0] = 1;
	for (int i = 1; i < maxn; i++) 
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]);
	}
}

LL ans , n , a[10] , b[10];

void dfs(LL deep)
{
	int i;
	if (deep == 10)
	{
		LL s = 0;
		for (i = 1 ; i <= 9 ; i++) s += b[i];
		if (s == 0) return;
		LL m = s+b[0];
		LL p = 1;
		if (b[0])
		{
			p *= c[m-1][b[0]];
			m -= b[0];
		}
		for (i = 1 ; i <= 9 ; i++)
		{
			if (b[i])
			{
				p *= c[m][b[i]];
				m -= b[i];
			}
		}
		ans += p;
	}
	else
	{
		if (!a[deep]) dfs(deep+1);
		for (i = 1 ; i <= a[deep] ; i++)
		{
			b[deep] = i;
			dfs(deep+1);
		}
	}
}

int main()
{
	createzuheshu();
	cin >> n;
	while (n > 0)
	{
		a[n%10]++;
		n /= 10;
	}
	dfs(0);
	cout << ans << "\n";
	return 0;
}