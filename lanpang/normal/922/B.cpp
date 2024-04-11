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

int i , j , k , n , ans;

int main()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		for (j = i ; j <= n ; j++)
		{
			k = i^j;
			if (k >= j && k <= n && k < i+j) 
			{
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}