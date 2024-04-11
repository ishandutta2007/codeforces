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

struct mmp{
	long long s , t; 
}a[200002] , b[200002];
long long n , m , k , t , s;
long long r , ma , ans;

bool cmp(struct mmp x , struct mmp y)
{
	return x.s > y.s;
}

int main ()
{
	int i , j;
	cin >> n >> m >> k >> t >> s;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%I64d",&a[i].t);
	}
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%I64d",&a[i].s);
		a[i].t = t-a[i].t;
	}
	m++;
	a[m].t = 0;
	a[m].s = 0;
	for (i = 1 ; i <= k ; i++)
	{
		scanf("%I64d",&b[i].t);
	}
	for (i = 1 ; i <= k ; i++)
	{
		scanf("%I64d",&b[i].s);
		if (b[i].t > n)
			b[i].t = n;
	}
	k++;
	b[k].t = 0;
	b[k].s = 0;
	sort(a+1,a+m+1,cmp);
	sort(b+1,b+k+1,cmp);
	ans = 0;
	ma = 0;
	r = k;
	for (i = 1 ; i <= m ; i++)
	{
		while (a[i].s+b[r].s <= s && r >= 1)
		{
			ma = max(ma,b[r].t);
			r--;
		}
		if (a[i].s <= s)
			ans = max(ans,ma*t+a[i].t*(n-ma));
	}
	ans = t*n-ans;
	if (ans >= 0)
		cout << ans << "\n";
	else
	    cout << "0\n";	
	//system("PAUSE");
	return 0;
}