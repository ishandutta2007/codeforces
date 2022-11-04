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
const int maxn = 1e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int a[maxn] , s[maxn] , k , n , f[maxn];
char c;
LL ans , cc[maxn][maxn];

void jisuan(int x)
{
	int i , j;
	if (s[n] == x) ans++;
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] == 1)
		{
			if (s[i-1] > x || x-s[i-1] > n-i) break;
			ans += cc[x-s[i-1]][n-i];
			ans %= mod;
		}
	}
}

int main ()
{
	int i , j , t;
	c = getchar();
	while (c >= '0' && c <= '1')
	{
		n++;
		a[n] = c-'0';
		s[n] = s[n-1]+a[n];
		c = getchar();
	}
	cin >> k;
	if (k <= 1) 
	{
		if (k == 0) cout << "1\n";
		else cout << n-1 << "\n";
	}
	else
	{
		for (i = 0 ; i <= 1000 ; i++) cc[0][i] = 1;
		for (i = 1 ; i <= 1000 ; i++)
		{
			for (j = i ; j <= 1000 ; j++)
			{
				cc[i][j] = cc[i-1][j-1]+cc[i][j-1];
				cc[i][j] %= mod;
			}
		}
		f[1] = 0;
		for (i = 2 ; i <= 1000 ; i++)
		{
			j = i;
			t = 0;
			while (j > 0)
			{
				t += j%2;
				j /= 2;
			} 
			f[i] = f[t]+1;
		} 
		for (i = 2 ; i <= 1000 ; i++)
		{
			if (f[i] == k-1)
			{
				jisuan(i); 
			} 
		} 
		cout << ans << "\n";
	}
	//system("PAUSE");
	return 0;
}