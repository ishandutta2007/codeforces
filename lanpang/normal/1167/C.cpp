#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;
const double eps = 1e-9;

int n , m , k , f[maxn] , s[maxn];

int getf(int x)
{
	if (f[x] != x) return f[x] = getf(f[x]);
	return f[x];
}

int main()
{
	int i , j , x , y;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		f[i] = i;
		s[i] = 1;
	}
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d",&k);
		for (j = 1 ; j <= k ; j++)
		{
			scanf("%d",&x);
			if (j > 1 && getf(x) != getf(y))
			{
				s[getf(x)] += s[getf(y)];
				f[getf(y)] = getf(x); 
			}
			y = x;
		}
	}
	for (i = 1 ; i <= n ; i++)
		printf("%d ",s[getf(i)]);
	return 0;
}