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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL a[maxn] , s , ss , n , i; 

int main()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i]);
		s += a[i];
	}
	for (i = 1 ; i <= n ; i++)
	{
		ss += a[i];
		if (ss*2 >= s)
		{
			cout << i << "\n";
			break;
		}
	}
	return 0;
}