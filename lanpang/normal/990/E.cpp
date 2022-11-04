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
const LL ma = 1e12+10;

int n , m , k , a[maxn] , b[maxn];
LL ans , s , mi;

int main()
{
	int i , j , la;
	cin >> n >> m >> k;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d",&j);
		a[j] = 1;
	}
	j = -1;
	for (i = 0 ; i <= n ; i++)
	{
		if (a[i] == 0) j = i;
		b[i] = j;
	}
	mi = ma;
	for (i = 1 ; i <= k ; i++)
	{
		scanf("%I64d",&s);
		ans = 0;
		la = -1;
		j = 0;
		while (j < n)
		{
			if (b[j] > la)
			{
				ans += s;
				la = b[j];
				j = b[j]+i;
			}
			else break;
		}
		if (j >= n) mi = min(mi,ans);
	}
	if (mi == ma) cout << "-1\n";
	else cout << mi << "\n";
	return 0;
}