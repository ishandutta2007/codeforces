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

int n , a[maxn] , i , j , b , c , b1 , b2;

int main()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> b;
		if (a[b] == 0) c++;
		a[b]++;
	}
	if (c == 2)
	{
		c = 0;
		for(i = 1 ; i <= 100 ; i++)
		{
			if (a[i] > 0)
			{
				for (j = i+1 ; j <= 100 ; j++)
				{
					if (a[j] > 0 && a[i] == a[j])
					{
						b1 = i;
						b2 = j;
						c = 1;
						break;
					}
				}
				break;
			}
		}
	}
	else c = 0;
	if (c == 1) cout << "YES\n" << b1 << " " << b2 << "\n";
	else cout << "NO\n";
	//system("PAUSE");
	return 0;
}