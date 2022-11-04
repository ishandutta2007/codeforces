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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , x , b[maxn] , m , mm;

int main ()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&x);
		if (i == 1)
		{
			m = x;
			b[x]--;
		}
		else
		{
			if (x > m)
			{
				mm = m;
				m = x;
				b[x]--;
			}
			else
			{
				if (x > mm)
				{
					mm = x;
					b[m]++;
				}
			}
		}
	}	
	m = 1;
	for (i = 2 ; i <= n ; i++)
	{
		if (b[i] > b[m])
		{
			m = i;
		}
	}
	cout << m << "\n";
	//system("PAUSE");
	return 0;
}