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

int n , f[maxn] , m , a[maxn] , g[maxn] , h[maxn];
LL ans;

int getf(int x)
{
	if (f[x] == x) return x;
	else 
	{
		f[x] = getf(f[x]); 
		return f[x]; 
	}
} 

int main ()
{
	int i , j , x , y , fx , fy;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		f[i] = i;
		h[i] = 1;
	}
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d",&x,&y);
		fx = getf(x);
		fy = getf(y);
		if (fx != fy)
		{
			f[fx] = fy;
			a[fy] = min(a[fy],a[fx]);
			a[fx] = 0;
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		ans += a[i];
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}