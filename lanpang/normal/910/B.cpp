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
const int maxn = 1e2+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a , b , f[10] , g[10] , ma;

int mmp()
{
	int ans = 1 , i , j;
	for (i = 1 ; i <= 6 ; i++)
	{
		for (j = 1 ; j <= 6 ; j++)
		{
			ans = max(ans,j);
			if (g[j] >= f[i]) 
			{
				g[j] -= f[i];
				break;
			}
		}
	}
	return ans;
}

int main ()
{
	int i , j , k;
	cin >> n >> a >> b;
	ma = 6;
	for (i = 1 ; i <= 5 ; i++)
	{
		for (j = i+1 ; j <= 6 ; j++)
		{
			for (k = 1 ; k <= 6 ; k++)
			{
				g[k] = n;
				if (i == k || j == k)
				{
					f[k] = b;
				}
				else
				{
					f[k] = a;
				}
			}
			ma = min(ma,mmp());
		}
	}
	cout << ma << "\n";
	//system("PAUSE");
	return 0;
}