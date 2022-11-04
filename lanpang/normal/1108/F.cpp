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

int n , m , f[maxn] , ans , tp;
struct mmp{
	int x , y , z;
	bool operator < (const mmp &op) const{
		return z < op.z;
	}
}a[maxn] , b[maxn];

int getf(int x)
{
	if (f[x] != x) f[x] = getf(f[x]);
	return f[x];
}

int main()
{
	int i , j , fx , fy;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		f[i] = i;
	for (i = 1 ; i <= m ; i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+m+1);
	for (i = 1 ; i <= m ; i++)
	{
		tp = 0;
		for (j = i ; j <= m && a[j].z == a[i].z ; j++)
		{
			fx = getf(a[j].x);
			fy = getf(a[j].y);
			if (fx != fy)
			{
				b[++tp].x = fx;
				b[tp].y = fy;
			}
			i = j;
		}
		for (j = 1 ; j <= tp ; j++)
		{
			fx = getf(b[j].x);
			fy = getf(b[j].y);
			if (fx != fy) f[fx] = fy;
			else ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}