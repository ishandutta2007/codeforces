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
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , k , a[maxn] , s[maxn] , ans;

int main()
{
	int i , j;
	cin >> n >> k;
	ans = n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&j);
		a[j]++;
	}
	for (i = 1 ; i <= 1000000 ; i++)
	{
		s[i] = s[i-1]+a[i];
	}
	for (i = 1 ; i <= 1000000 ; i++)
	{
		if (s[min(1000000,i+k)]-s[i]) ans -= a[i];
	}
	cout << ans << "\n";
	return 0;
}