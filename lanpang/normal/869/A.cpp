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
const int maxn = 2e3+10;
const int maxm = 4e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , b[maxn] , c[maxm] , i , j , ans;

int main ()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		c[a[i]] = 1;
	}
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&b[i]);
		c[b[i]] = 1;
	}
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= n ; j++)
		{
			ans += c[a[i]^b[j]];
		}
	}
	if (ans%2) cout << "Koyomi\n";
	else cout << "Karen\n";
	//system("PAUSE");
	return 0;
}