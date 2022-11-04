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

int n , m , b[maxn] , ans , l , t;
char a[maxn] , c;

int main ()
{
	int i , j;
	cin >> n >> m;
	for (i = 0 ; i <= n ; i++)
	{
		a[i] = getchar();
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] == '1')
		{
			l++;
			a[l] = i;
		}
	}
	t = 1;
	j = 1;
	while (t < n)
	{
		while (j <= l && a[j] <= t+m)
		{
			j++;
		}
		j--;
		if (t == a[j]) 
		{
			ans = -1;
			break;
		}
		t = a[j];
		ans++;
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}