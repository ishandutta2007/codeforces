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

char a[5010];
int i , j , x , y , n , ans;

int main ()
{
	cin >> a;
	n = strlen(a);
	for (i = 0 ; i < n ; i++)
	{
		j = i;
		x = 0;
		y = 0;
		while (j < n)
		{
			if (a[j] == '?') 
			{
				if (y < x) y++;
				else x++;
			}
			else
			{
				if (a[j] == '(') x++;
				else 
				{
					if (x > 0) 
					{
						x--;
						if (y > x) 
						{
							y--;
							x++;
						}
					}
					else
					{
						if (y > 0) y--;
						else break;
					}
				}
			}
			if (y == x) ans++;
			j++;
		}
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}