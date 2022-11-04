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
const int maxn = 3e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	LL n , p;
}a[maxn];

LL n , f[maxn] , ans , k , top , g[maxn];

bool cmp(mmp x , mmp y)
{
	if (x.n == y.n) return x.p > y.p;
	else return x.n > y.n;
}

int main ()
{
	top = 1;
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i].n);
		a[i].p = i;
	}
	sort(a+1,a+n+1,cmp);
	top = 1;
	for (int i = 1 ; i <= n ; i++)
	{
		while (f[top]) top++;
		if (a[i].p > k && f[a[i].p-k] == 0) 
		{
			f[a[i].p-k] = 1;
			g[a[i].p] = a[i].p;
		}
		else
		{
			f[top] = 1;
			g[a[i].p] = top+k;
			ans += (top+k-a[i].p)*a[i].n;
		}
	}
	cout << ans << "\n";
	for (int i = 1 ; i < n ; i++)
	{
		printf("%I64d ",g[i]);
	}
	cout << g[n] << "\n";
	//system("PAUSE");
	return 0;
}