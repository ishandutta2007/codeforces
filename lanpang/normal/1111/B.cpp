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

LL n , k , m , a[maxn] , s[maxn] , sum;
double ma;

int main()
{
	LL i , j;
	cin >> n >> k >> m;
	for (i = 1 ; i <= n ; i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (i = 1 ; i <= n ; i++)
		s[i] = s[i-1]+a[i];
	for (i = max(1ll,n-m) ; i <= n ; i++)
	{
		sum = s[i]+min((m-n+i),i*k);
		ma = max(ma,((double)sum)/((double)i));
	}
	printf("%.8lf\n",ma);
	return 0;
}