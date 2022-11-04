#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

struct mmp{
	int x , y , z , i;
	bool operator < (const mmp &op) const{
		if (x != op.x) return x < op.x;
		if (y != op.y) return y < op.y;
		return z < op.z;
	}
}a[maxn] , b[maxn];
int n , tp;

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		a[i].i = i;
	}
	sort(a+1,a+n+1);
	for (i = 1 ; i <= n ; i++)
	{
		if (i < n && a[i].x == a[i+1].x && a[i].y == a[i+1].y)
		{
			printf("%d %d\n",a[i].i,a[i+1].i);
			i++;
			continue;
		}
		b[++tp] = a[i];
	}
	n = tp;
	tp = 0;
	for (i = 1 ; i <= n ; i++)
	{
		if (i < n && b[i].x == b[i+1].x)
		{
			printf("%d %d\n",b[i].i,b[i+1].i);
			i++;
			continue;
		}
		a[++tp] = b[i];
	}
	n = tp;
	for (i = 1 ; i <= n ; i += 2)
		printf("%d %d\n",a[i].i,a[i+1].i);
	return 0;
}