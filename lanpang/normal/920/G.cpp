#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int t , m , n , k;
int la , a[50] , b[1010];

void fenjie(int x)
{
	int i;
	la = 0;
	for (i = 2 ; i <= sqrt(x) ; i++)
	{
		if (x % i == 0)
		{
			la++;
			a[la] = i;
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1)
	{
		la++;
		a[la] = x;
	}
}

int getcnt(int x)
{
	int g=0 , cnt=x , h , i , j;
	b[++g] = 1;
	for (i = 1 ; i <= la ; i++)
	{
		h = g;
		for (j = 1 ; j <= g ; j++)
		{
			b[++h] = b[j]*a[i]*-1;
			cnt += x/b[h];
		}
		g = h;
	}
	return cnt;
}
 
int erfen(int x)
{
	int m , l=1 , r=mod;
	while (l <= r)
	{
		m = (l+r)/2;
		if (getcnt(m) < x) l = m+1;
		else r = m-1;
	}
	return l;
} 
 
int main()
{
	cin >> t;
	while (t--)
	{
		scanf("%d%d%d",&m,&n,&k);
		fenjie(n);
		printf("%d\n",erfen(k+getcnt(m)));
	}
	//system("PAUSE");
	return 0;
}