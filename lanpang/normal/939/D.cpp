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

int n , m , f[30];
char a[maxn] , b[maxn] , c[30] , d[30];

int getf(int x)
{
	if (f[x] != x) f[x] = getf(f[x]);
	return f[x];
}

int main()
{
	int i , x , y;
	cin >> n;
	scanf("%s",a);
	scanf("%s",b);
	for (i = 0 ; i < 26 ; i++) f[i] = i;
	for (i = 0 ; i < n ; i++)
	{
		if (a[i] != b[i])
		{
			x = a[i]-'a';
			y = b[i]-'a';
			x = getf(x);
			y = getf(y);
			if (x != y)
			{
				m++;
				c[m] = a[i];
				d[m] = b[i];
				f[x] = y;
			}
		}
	}
	cout << m << "\n";
	for (i = 1 ; i <= m ; i++)
	{
		cout << c[i] << " " << d[i] << "\n";
	}
	return 0;
}