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
const LL mod = 998244353;

LL k , a[110][110] , b[110][110] , c[110][110] , n , m;

void MQP(LL x , LL MOD)
{
	if (x == 1)
	{
		for (int i = 1 ; i <= k ; i++)
			for (int j = 1 ; j <= k ; j++)
				b[i][j] = a[i][j];
		return;
	}
	MQP(x/2,mod-1);
	for (int i = 1 ; i <= k ; i++)
		for (int j = 1 ; j <= k ; j++)
			c[i][j] = a[i][j];
	for (int i = 1 ; i <= k ; i++)
	{
		for (int j = 1 ; j <= k ; j++)
		{
			a[i][j] = 0;
			for (int l = 1 ; l <= k ; l++)
				a[i][j] = (a[i][j]+c[i][l]*c[l][j])%MOD;
		}
	}
	if (x%2 == 0) return;
	for (int i = 1 ; i <= k ; i++)
		for (int j = 1 ; j <= k ; j++)
			c[i][j] = a[i][j];
	for (int i = 1 ; i <= k ; i++)
	{
		for (int j = 1 ; j <= k ; j++)
		{
			a[i][j] = 0;
			for (int l = 1 ; l <= k ; l++)
				a[i][j] = (a[i][j]+b[i][l]*c[l][j])%MOD;
		}
	}
}

LL BSGS(LL A , LL C , LL MOD) //A ^ B % MOD = C && gcd(A,MOD) = 1
{
	A %= MOD;
	C %= MOD;
	if (C == 1) return 0;
	LL T = (LL)sqrt(MOD+0.5) , AT = 1 , S = 1;
	map<LL,LL> mp;
	mp[C] = 0;
	for (LL i = 1 ; i <= T ; i++)
	{
		C = C*A%MOD;
		mp[C] = i;
		AT = AT*A%MOD;
	}
	for (LL i = 1 ; i <= T ; i++)
	{
		S = S*AT%MOD;
		if (mp.count(S))
			return i*T-mp[S];
	}
	return -1;
}

LL EXGCD(LL A , LL B , LL &x , LL &y)
{
	if (B == 0)
	{
		x = 1;
		y = 0;
		return A;
	}
	LL ret = EXGCD(B,A%B,x,y);
	LL xx = x , yy = y;
	x = yy;
	y = xx-A/B*yy;
	return ret;
}

LL qp(LL x , LL y , LL MOD)
{
	if (y == 0) return 1;
	LL z = qp(x,y/2,MOD);
	if (y%2) return z*z%MOD*x%MOD;
	else return z*z%MOD;
}

int main()
{
	LL i , j , ret , x , y , gcd , xx;
	cin >> k;
	for (i = 1 ; i <= k ; i++)
	{
		cin >> j;
		a[1][i] = j;
		if (i < k) a[i+1][i] = 1;
	}
	cin >> n >> m;
	MQP(n-k,mod-1);
	ret = BSGS(3,m,mod);
	if (ret == -1)
	{
		cout << "-1\n";
		return 0;
	}
	gcd = EXGCD(a[1][1],mod-1,x,y);
	if (ret%gcd != 0)
	{
		cout << "-1\n";
		return 0;
	}
	x = ret/gcd*x;
	xx = (mod-1)/gcd;
	x = (x%xx+xx)%xx;
	cout << qp(3,x,mod) << "\n";
	return 0;
}