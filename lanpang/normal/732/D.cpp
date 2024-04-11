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

int n , m , a[maxn] , b[maxn] , c[maxn];

bool check(int x)
{
	int i , p=0 , s=0;
	for (i = 1 ; i <= m ; i++) c[i] = 0;
	for (i = x ; i >= 1 ; i--)
		if (a[i] > 0 && c[a[i]] == 0)
		{
			c[a[i]] = 1;
			s++;
			p += b[a[i]];
		}
		else p = max(p-1,0);
	if (s == m && p == 0) return true;
	else return false;
}

int main()
{
	int i , l , r , mid;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++) cin >> a[i];
	for (i = 1 ; i <= m ; i++) cin >> b[i];
	l = 1;
	r = n;
	while (l <= r)
	{
		mid = (l+r)/2;
		if (check(mid)) r = mid-1;
		else l = mid+1;
	}
	if (l <= n) cout << l << "\n";
	else cout << "-1\n";
	return 0;
}