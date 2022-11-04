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

int n , a , i , j , c;

int main ()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a;
		c = 0;
		for (j = 0 ; j <= a/3 ; j++)
		{
			if ((a-(j*3))%7==0)
			{
				c = 1;
				break;
			}
		}
		if (c) cout << "YES\n";
		else cout << "NO\n";
	}
	//system("PAUSE");
	return 0;
}