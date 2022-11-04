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

const LL mod = 1e9+7;
LL n , k , a[maxn] , ll[maxn] , rr[maxn] , q[maxn] , top , ans , i;

LL count(LL l, LL r) 
{
	LL lb = l / k;
	l %= k;
	LL rb = r / k;
	r %= k;
	LL ret = k * lb % mod * rb % mod;
	ret = (ret + l * rb + r * lb) % mod;
	if (l && r) 
	{
		l--;
		r--;
		ret = (ret + 1) % mod;
		if (l + r >= k - 1)
			ret = (ret + l + r - (k - 1)) % mod;
	}
	return (ret+mod-1)%mod;
}

int main()
{
	cin >> n >> k;
	k--;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i]);
	}
	a[0] = mod;
	top = 1;
	q[1] = 0;
	for (i = 1 ; i <= n ; i++)
	{
		while (a[q[top]] < a[i]) top--;
		ll[i] = q[top];
		q[++top] = i;
	}
	a[n+1] = mod;
	top = 1;
	q[1] = n+1;
	for (i = n ; i >= 1 ; i--)
	{
		while (a[q[top]] <= a[i]) top--;
		rr[i] = q[top];
		q[++top] = i;
	}
	for (i = 1 ; i <= n ; i++)
	{
		ans = (ans+count(i-ll[i],rr[i]-i)*a[i])%mod;
	}
	cout << ans << "\n";
	return 0;
}