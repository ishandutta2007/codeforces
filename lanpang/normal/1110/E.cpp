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

int n , a[maxn] , b[maxn] , c[maxn] , d[maxn];

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		b[i] = a[i]-a[i-1];
	}
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&c[i]);
		d[i] = c[i]-c[i-1];
	}
	if (b[1] != d[1])
	{
		cout << "No\n";
		return 0;
	}
	sort(b+1,b+n+1);
	sort(d+1,d+n+1);
	for (i = 1 ; i <= n ; i++)
	{
		if (b[i] != d[i])
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}