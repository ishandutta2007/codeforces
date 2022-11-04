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

char a[10000];
int l , f[2][10000] , mi;

int main ()
{
	int i , j;
	cin >> a;
	l = strlen(a);
	for (i = 0 ; i < l ; i++)
	{
		if (i > 0)
		{
			f[0][i] = f[0][i-1];
			f[1][i] = f[1][i-1];
		}
		if (a[i] == 'a')
		{
			f[0][i]++;
		}
		else
		{
			f[1][i]++;
		}
	}
	mi = f[1][l-1];
	for (i = 0 ; i < l ; i++)
	{
		mi = min(mi,f[0][i]+f[1][l-1]-f[1][i]);
	}
	for (i = 0 ; i < l ; i++)
	{
		for (j = i ; j < l ; j++)
		{
			mi = min(mi,f[1][i]+f[0][j]-f[0][i]+f[1][l-1]-f[1][j]);
		}
	}
	cout << l-mi << "\n";
	//system("PAUSE");
	return 0;
}