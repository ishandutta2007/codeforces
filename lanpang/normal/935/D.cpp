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

LL n , m , a[maxn] , b[maxn] , i;

LL qp(LL x , LL y)
{
	if (y == 0) return 1;
	if (y == 1) return x;
	LL z = qp(x,y/2);
	if (y%2) return z*z%mod*x%mod;
	else return z*z%mod;
}

LL jisuan(LL i)
{
	if (i > n) return 0;
	if (a[i] == 0 && b[i] == 0)
	{
		return ((m-1)*qp(2,mod-2)%mod+jisuan(i+1))*qp(m,mod-2)%mod;
	}
	if (a[i] != 0 && b[i] == 0)
	{
		return (a[i]-1+jisuan(i+1))*qp(m,mod-2)%mod;
	}
	if (a[i] == 0 && b[i] != 0)
	{
		return (m-b[i]+jisuan(i+1))*qp(m,mod-2)%mod;
	} 
	if (a[i] != 0 && b[i] != 0)
	{
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return 0;
		return jisuan(i+1);
	}
}

int main()
{
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i]);
	}
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&b[i]);
	}
	cout << jisuan(1) << "\n";
	return 0;
}