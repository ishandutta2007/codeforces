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
const LL mod = 1e9+7;

LL n , m , a[maxn] , c[maxn] , t , d , ans;
struct mmp{
	LL x , id;
	bool operator < (const mmp &op) const{
		if (x == op.x) return id < op.id;
		else return x < op.x;
	}
}p;
set<mmp> s;

int main()
{
	LL i , j , x;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		scanf("%I64d",&a[i]);
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&c[i]);
		p.x = c[i];
		p.id = i;
		s.insert(p);
	}
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%I64d%I64d",&t,&d);
		j = min(d,a[t]);
		ans = j*c[t];
		d -= j;
		a[t] -= j;
		while (d > 0 && !s.empty())
		{
			x = (*s.begin()).id;
			j = min(d,a[x]);
			ans += j*c[x];
			d -= j;
			a[x] -= j;
			if (a[x] == 0) s.erase(s.begin());
		}
		if (d > 0) ans = 0;
		printf("%I64d\n",ans);
	}
	return 0;
}