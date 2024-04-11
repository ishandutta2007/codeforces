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

int n , a[maxn] , s[maxn] , l , r , ans , ma , mi;

int main()
{
	int i;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		a[n+i] = a[i];
	}
	for (i = 1 ; i <= n+n ; i++)
	{
		s[i] = s[i-1]+a[i];
	}
	cin >> l >> r;
	ma = 0;
	mi = 0;
	for (i = 1 ; i <= n ; i++)
	{
		ans = s[n-i+r]-s[n-i+l];
		if (ans > ma)
		{
			ma = ans;
			mi = i;
		}
	}
	cout << mi << "\n";
	return 0;
}