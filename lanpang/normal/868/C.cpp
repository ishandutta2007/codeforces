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

int n , k , a[20] , m , f[maxn];

int main ()
{
	int i , j , x;
	cin >> n >> k;
	m = 1;
	for (i = 1 ; i <= k ; i++)
	{
		m *= 2;
	}
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&f[i]);
		for (j = 2 ; j <= k ; j++) 
		{
			scanf("%d",&x);
			f[i] = f[i]*2+x;
		}
		a[f[i]]++;
	} 
	int c = 0;
	for (i = 1 ; i <= n ; i++)
		for (j = 0 ; j < m ; j++)
			if ((f[i]&j) == 0 && a[j] > 0) c = 1;
	if (c) cout << "YES\n";
	else cout << "NO\n";
	//system("PAUSE");
	return 0;
}