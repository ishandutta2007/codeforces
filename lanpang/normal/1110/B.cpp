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

LL n , m , k , a[maxn] , ans , b[maxn];

int main()
{
	LL i , j;
	cin >> n >> m >> k;
	ans = n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%lld",&a[i]);
		if (i > 1) b[i-1] = a[i]-a[i-1]-1;
	}
	sort(b+1,b+n);
	for (i = 1 ; i <= n-k ; i++)
		ans += b[i];
	cout << ans << "\n";
	return 0;
}