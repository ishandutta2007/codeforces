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

int n , k , m , a[maxn] , b[maxn] , ma , p; 

int main ()
{
	int i , j;
	cin >> n >> k >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&b[i]);
		a[b[i]%m]++;
	}
	for (i = 0 ; i < m ; i++)
		ma = max(ma,a[i]);
	if (ma >= k)
	{
		cout << "Yes\n";
		for (i = 0 ; i < m ; i++)
			if (a[i] == ma) break;
		for (j = 1 ; j <= n ; j++)
		{
			if (b[j]%m == i)
			{
				printf("%d ",b[j]);
				p++;
				if (p == k) break;
			}
		}
		cout << "\n";
	}
	else cout << "No\n";
	//system("PAUSE");
	return 0;
}