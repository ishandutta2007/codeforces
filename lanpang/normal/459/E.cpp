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
const int mod = 1e9+7;

struct mmp{
	int x , y , z;
	bool operator < (const mmp &op) const{
		return z < op.z;
	}
}a[maxn];
int n , m , f[maxn][2] , ans , i , j , k;

int main()
{
	cin >> n >> m;
	for (i = 1 ; i <= m ; i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+m+1);
	for (i = 1 ; i <= m ; i++)
	{
		for (j = i ; j <= m && a[j].z == a[i].z ; j++)
		{
			f[a[j].y][1] = max(f[a[j].y][1],f[a[j].x][0]+1);
			ans = max(ans,f[a[j].y][1]);
		}
		j--;
		for (k = i ; k <= j ; k++)
			f[a[k].y][0] = f[a[k].y][1];
		i = j;
	}
	cout << ans << "\n";
	return 0;
}