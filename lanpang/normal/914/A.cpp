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

int n , a[1001] , m = -1000001 , sa , i;

int main ()
{	
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		if (a[i] < 0) 
		{
			m = max(m,a[i]);
		}
		else
		{
			sa = sqrt(a[i]);
			if (sa*sa != a[i]) m = max(m,a[i]);
		}
	} 
	cout << m << "\n";
	//system("PAUSE");
	return 0;
}