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

int n , a[200][200];

int main ()
{
	int i , j , t;
	cin >> n;
	a[0][0] = 1;
	a[1][0] = 0;
	a[1][1] = 1;
	for (i = 2 ; i <= n ; i++)
	{
		a[i][0] = a[i-2][0];
		t = 0; 
		for (j = 1 ; j <= i ; j++)
		{
			a[i][j] = a[i-1][j-1]+a[i-2][j];
			if (a[i][j] > 1 || a[i][j] < -1) t = -2;
		}
		for (j = 0 ; j <= i ; j++)
		{
			a[i][j] += t*a[i-2][j];
		}
	}
	cout << n << "\n";
	for (i = 0 ; i <= n ; i++)
	{
		cout << a[n][i] << " ";
	}
	cout << "\n";
	cout << n-1 << "\n";
	for (i = 0 ; i < n ; i++)
	{
		cout << a[n-1][i] << " ";
	}
	cout << "\n";
	//system("PAUSE");
	return 0;
}