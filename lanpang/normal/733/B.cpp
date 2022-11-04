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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , b[maxn] , sa , sb , ma , ans;

int main()
{
	int i;
	cin >> n;
	for (i = 1 ; i <= n ; i++) 
	{
		cin >> a[i] >> b[i];
		sa += a[i];
		sb += b[i];
	}
	ans = 0;
	ma = fabs(sa-sb);
	for (i = 1 ; i <= n ; i++) 
	{
		if (fabs((sa-a[i]+b[i])-(sb-b[i]+a[i])) > ma)
		{
			ans = i;
			ma = fabs((sa-a[i]+b[i])-(sb-b[i]+a[i]));
		}
	}
	cout << ans << "\n";
	return 0;
}