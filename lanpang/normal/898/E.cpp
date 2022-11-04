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

LL n , a[maxn] , d , d0 , b[maxn] , m , g , ans;

int main ()
{
	LL i , j , k;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i]);
		k = sqrt(a[i]);
		if (k*k == a[i]) 
		{
			d++;
			if (!a[i]) d0++;
		}
		else
		{
			m++;
			b[m] = min(a[i]-k*k,(k+1)*(k+1)-a[i]);
		}
	}
	if (d >= n/2)
	{
		if (d == n/2) cout << "0\n";
		else if (d0 <= n/2) cout << d-n/2 << "\n";
		else cout << d-n/2+d0-n/2 << "\n";
	} 
	else
	{
		g = n/2-d;
		sort(b+1,b+m+1);
		for (i = 1 ; i <= g ; i++)
		{
			ans += b[i];
		}
		cout << ans << "\n";
	}
	//system("PAUSE");
	return 0;
}