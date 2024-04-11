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

int n , a[110] , x , y , z , t , i;

int main ()
{
	x = 1;
	y = 2;
	z = 3;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] == z)
		{
			t = 1;
			break;
		}
		else
		{
			if (a[i] == x) swap(y,z);
			else swap(x,z);
		}
	}
	if (t) cout << "NO\n";
	else cout << "YES\n";
	//system("PAUSE");
	return 0;
}