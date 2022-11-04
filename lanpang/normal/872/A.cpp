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

int n , m , a1 , b1 , a , b , i , f[10] , ff[10] , c;

int main ()
{
	a1 = 10;
	b1 = 10;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a;
		a1 = min(a1,a); 
		f[a] = 1;
	}
	for (i = 1 ; i <= m ; i++)
	{
		cin >> b;
		b1 = min(b1,b); 
		ff[b] = 1;
	}
	for (i = 1 ; i <= 9 ; i++)
		if (f[i]&&ff[i]&&c==0) 
		{
			cout << i << "\n";
			c = 1;
		}
	if (!c)
		cout << min(a1,b1) << max(a1,b1) << "\n"; 
	//system("PAUSE");
	return 0;
}