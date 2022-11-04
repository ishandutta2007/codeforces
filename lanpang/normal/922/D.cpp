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
}a[maxn];
int n;
LL ans , s;
char c[maxn];

bool cmp(mmp x , mmp y)
{
	return x.x*y.y > x.y*y.x;
}

int main()
{
	int i , j , k;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%s",c);
		k = strlen(c);
		for (j = 0 ; j < k ; j++)
		{
			if (c[j] == 's') a[i].x++;
			else 
			{
				a[i].y++;
				ans += a[i].x;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	s = 0;
	for (i = 1 ; i <= n ; i++)
	{
		ans += s*a[i].y;
		s += a[i].x;
	}
	cout << ans << "\n";
	return 0;
}