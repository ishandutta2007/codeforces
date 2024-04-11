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
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL n , m , a[maxn] , i , k , s; 

int main()
{
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+n+1);
	k = (n+1)/2;
	if (a[k] > m)
	{
		while (a[k] > m)
		{
			s += a[k]-m;
			k--;
			if (k < 1) break;
		}
	}
	else
	{
		while (a[k] < m)
		{
			s += m-a[k];
			k++;
			if (k > n) break;
		}
	}
	cout << s << "\n";
	return 0;
}