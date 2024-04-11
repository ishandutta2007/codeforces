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

struct mmp{
	int x , s;
	bool operator < (const mmp &op) const{
		return x < op.x;
	}
}f[4100][4100] , gg;
int n , m , q , w[20];
int a[4100] , ty , ss , s[4100][4100];
char c[20];

int main()
{
	int i , j , k;
	cin >> n >> m >> q;
	for (i = n-1 ; i >= 0 ; i--) 
	{
		cin >> w[i];
	} 
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%s",c);
		ty = 0;
		for (j = 0 ; j < n ; j++)
		{
			if (c[n-1-j] == '1') ty += (1 << j);
		}
		a[ty]++;
	}
	for (i = 0 ; i < (1 << n) ; i++)
	{
		for (j = 0 ; j < (1 << n) ; j++)
		{
			ss = 0;
			for (k = 0 ; k < n ; k++)
			{
				if (((i >> k) & 1) == ((j >> k) & 1)) ss += w[k];
			}
			f[i][j].x = ss;
			f[i][j].s = a[j];
		}
		sort(f[i],f[i]+(1 << n));
		s[i][0] = f[i][0].s;
		for (j = 1 ; j < (1 << n) ; j++)
		{
			s[i][j] = s[i][j-1]+f[i][j].s;
		}
	} 
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%s %d",c,&k);
		gg.x = k;
		ty = 0;
		for (j = 0 ; j < n ; j++)
		{
			if (c[n-1-j] == '1') ty += (1 << j);
		}
		j = upper_bound(f[ty],f[ty]+(1 << n),gg)-f[ty]-1;
		printf("%d\n",s[ty][j]);
	} 
	return 0;
}