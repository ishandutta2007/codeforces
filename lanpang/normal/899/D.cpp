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

LL n , a[100] , ans;

LL mmp(LL x)
{
	return max((LL)0,min(n-x+1,x-1));
}

int main ()
{
	LL i , j;
	cin >> n;
	if (n <= 4)
	{
		if (n == 2) cout << "1\n";
		if (n == 3) cout << "3\n";
		if (n == 4) cout << "6\n";
	}
	else
	{
		a[1] = 5;
		for (i = 2 ; i <= 10 ; i++)
		{
			a[i] = a[i-1]*10;
		}
		i = 1;
		while (i <= 10 && a[i] <= n) i++;
		i--;
		for (j = 1 ; j <= 9 ; j++)
		{
			ans += mmp(a[i]*j);
		}
		cout << ans << "\n";
	}
	//system("PAUSE");
	return 0;
}