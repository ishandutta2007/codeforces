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

int f[10] , i , j , k , cnt , b[60];
char c[10] , a[60][60];

int main()
{
	cin >> f[1] >> f[2] >> f[3] >> f[4];
	c[1] = 'A';
	c[2] = 'B';
	c[3] = 'C';
	c[4] = 'D';
	for (i = 1 ; i <= 3 ; i++)
	{
		if (f[i] < f[i+1])
		{
			swap(f[i],f[i+1]);
			swap(c[i],c[i+1]);
		}
	}
	for (i = 1 ; i <= 50 ; i += 2)
	{
		for (j = 1 ; j <= 50 ; j += 2)
		{
			k = ((i%6)+1)/2;
			if (f[k])
			{
				b[i]++;
				f[k]--;
				a[i][j] = c[k];
			}
		}
	}
	for (i = 1 ; i <= 50 ; i += 2)
	{
		cnt = 0;
		for (j = 1 ; j <= 50 ; j += 2)
		{
			k = ((i%6)+1)/2;
			if (f[4] > 1 && b[i] > 1)
			{
				cnt++;
				b[i]--;
				if (cnt%2)
				{
					f[4]--;
					a[i+1][j] = c[k];
					a[i+1][j+1] = c[k];
				}
			}
		}
	}
	for (i = 1 ; i <= 50 ; i++)
	{
		for (j = 1 ; j <= 50 ; j++)
		{
			if (a[i][j] != c[1] && a[i][j] != c[2] && a[i][j] != c[3]) a[i][j] = c[4];
		}
	}
	cout << "50 50\n";
	for (i = 1 ; i <= 50 ; i++)
	{
		for (j = 1 ; j <= 50 ; j++)
		{
			cout << a[i][j];
		}
		cout << "\n";
	}
	return 0;
}