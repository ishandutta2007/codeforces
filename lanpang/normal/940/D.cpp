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

int n , a[maxn] , m , l1 , r2;
char b[maxn];

int main()
{
	int i , j;
	cin >> n;
	for (i = 0 ; i < n ; i++) 
	{
		scanf("%d",&a[i]);
	}
	scanf("%s",b);
	l1 = -mod;
	r2 = mod;
	for (i = 4 ; i < n ; i++)
	{
		if (b[i] == '1' && b[i-1] == '0' && b[i-2] == '0' && b[i-3] == '0' && b[i-4] == '0')
		{
			m = max(a[i],max(a[i-1],max(a[i-2],max(a[i-3],a[i-4]))));
			l1 = max(l1,m+1);
		}
		if (b[i] == '0' && b[i-1] == '1' && b[i-2] == '1' && b[i-3] == '1' && b[i-4] == '1')
		{
			m = min(a[i],min(a[i-1],min(a[i-2],min(a[i-3],a[i-4]))));
			r2 = min(r2,m-1);
		}
	}
	if (l1 == -mod) l1 = -1e9;
	if (r2 == mod) r2 = 1e9;
	cout << l1 << " " << r2 << "\n";
	return 0;
}