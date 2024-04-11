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

char a[100][100] , c , b[200];
int n , m , l , px , py , f[10] , g[10] , s;

int check1()
{
	for (int i = 0 ; i <= 3 ; i++) g[i] = 0;
	for (int i = 0 ; i <= 3 ; i++)
	{
		g[f[i]] = 1;
		for (int j = 0 ; j <= 3 ; j++)
		{
			if (i != j && f[i] == f[j]) return 0;
		}
	}
	for (int i = 0 ; i <= 3 ; i++)
	{
		if (g[i] == 0) return 0;
	}
	return 1;
}

int main ()
{
	int i , j , x , y , t;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		c = getchar();
		for (j = 1 ; j <= m ; j++)
		{
			a[i][j] = getchar();
			if (a[i][j] == 'S') 
			{
				x = i;
				y = j;
			}
		}
	}
	cin >> b;
	l = strlen(b);
	for (i = 123 ; i <= 3210 ; i++)
	{
		f[0] = i/1000;
		f[1] = i/100%10;
		f[2] = i/10%10;
		f[3] = i%10;
		if (check1())
		{
			t = 0;
			px = x;
			py = y;
			for (j = 0 ; j < l ; j++)
			{
				if (f[b[j]-'0'] == 0) px++;
				if (f[b[j]-'0'] == 1) py++;
				if (f[b[j]-'0'] == 2) px--;
				if (f[b[j]-'0'] == 3) py--;
				if (px < 1 || px > n || py < 1 || py > m || a[px][py] == '#') break;
				if (a[px][py] == 'E')
				{
					t = 1;
					break;
				}
			}
			s += t;
		}
	}
	cout << s << "\n";
	//system("PAUSE");
	return 0;
}