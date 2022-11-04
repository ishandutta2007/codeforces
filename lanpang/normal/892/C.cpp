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
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , i , j , a[maxn] , c , s , gcd[maxn][maxn];

int main ()
{
	cin >> n;
	s = n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		gcd[i][i] = a[i];
		if (a[i] == 1) s--;
	}
	if (s < n) cout << s << "\n";
	else
	{
		for (i = 1 ; i < n ; i++)
		{
			for (j = i+1 ; j <= n ; j++)
			{
				gcd[i][j] = __gcd(gcd[i][j-1],a[j]);
			} 
		}
		for (i = 1 ; i < n ; i++)
		{
			for (j = 1 ; j+i <= n ; j++)
			{
				if (gcd[j][i+j] == 1)
				{
 					c = 1;
					break;
				}
			} 
			if (c) break; 
		}
		if (c) cout << s+i-1 << "\n";
		else cout << "-1\n";
	}
	//system("PAUSE");
	return 0;
}