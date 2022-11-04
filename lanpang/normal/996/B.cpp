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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , ans , p;

int main()
{
	int i;
	ans = mod;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		a[i] = a[i]-i+1;
		if (ans > (a[i]+n-1)/n*n+i-1)
		{
			ans = (a[i]+n-1)/n*n+i-1;
			p = i;
		}
	}
	cout << p << "\n";
	return 0;
}