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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	LL x , y;
	mmp(LL x=0 , LL y=0):x(x),y(y){}
	bool operator > (const mmp op) const{
		return y > op.y;
	}
}mp;

priority_queue< mmp,vector<mmp>,greater<mmp> > q;
LL n , m , a[maxn] , dp[maxn] , s;

int main()
{
	LL i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i]);
	}
	for (i = 1 ; i <= n ; i++)
	{
		dp[i] = dp[i-1]+a[i];
		s += a[i];
		mp.x = i;
		mp.y = a[i];
		q.push(mp);
		if (i > m) s -= a[i-m];
		if (i >= m)
		{
			while (q.top().x <= i-m) q.pop();
			dp[i] = min(dp[i],dp[i-m]+s-q.top().y);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}