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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+9;

LL n , a , b , k , f[maxn] , ans;
char c;

LL qp(LL x , LL y)
{
	if (y == 0) return (LL)1;
	LL z = qp(x,y/2);
	if (y%2 == 0) return z*z%mod;
	else return z*z%mod*x%mod;
}

int main()
{
	LL i , j , h , g , p;
	cin >> n >> a >> b >> k;
	n++;
	for (i = 1 ; i <= k ; i++)
	{
		cin >> c;
		if (c == '+') f[i] = (LL)1;
		else f[i] = (LL)-1;
	}
	for (i = 1 ; i <= min(n,k) ; i++)
	{
		j = (n-i)/k+1;
		h = f[i]*qp(a,n-i)*qp(b,i-1)%mod;
		g = qp(qp(a,mod-2),k)*qp(b,k)%mod;
		if (g == 1) ans = (ans+h*j%mod)%mod;
		else
		{
			p = qp(g,j);
			ans = (ans+h*(p-1)%mod*qp(g-1,mod-2)%mod)%mod;
		}
	}
	if (ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}