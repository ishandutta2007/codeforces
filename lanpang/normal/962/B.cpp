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

char a[maxn];
int n , x , y , top , b[maxn] , xx , yy;

int main()
{
	int i , j;
	cin >> n >> xx >> yy >> a;
	x = xx;
	y = yy;
	a[n] = '*';
	for (i = 0 ; i <= n ; i++)
	{
		j = i;
		while (a[j] == '.') j++;
		if (j > i)
		{
			top++;
			b[top] = j-i;
			i = j;
		}
	}
	for (i = 1 ; i <= top ; i++)
	{
		if (b[i]%2)
		{
			if (x > y)
			{
				x = max(0,x-b[i]/2-1);
				y = max(0,y-b[i]/2);
			}
			else
			{
				x = max(0,x-b[i]/2);
				y = max(0,y-b[i]/2-1);
			}
		}
		else
		{
				x = max(0,x-b[i]/2);
				y = max(0,y-b[i]/2);
		}
	}
	cout << xx+yy-x-y << "\n";
	return 0;
}