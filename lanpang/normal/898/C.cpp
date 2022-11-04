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

int n , l[30] , len , k , m , lq[30] , llq[30][1000] , f[30][1000] , mm;
char a[30][30] , b[30] , c , q[30][1000][30];

int main ()
{
	int i , j , h , t , g;
	cin >> n;
	c = getchar();
	for (i = 1 ; i <= n ; i++)
	{
		len = 0;
		c = getchar();
		while (c != ' ')
		{
			b[len] = c;
			len++;
			c = getchar();
		}
		b[len] = '\0';
		t = -1;
		for (j = 1 ; j <= m ; j++)
		{
			g = 1;
			if (len == l[j])
			{
				g = 0;
				for (h = 0 ; h < l[j] ; h++)
				{
					if (a[j][h] != b[h]) 
					{
						g = 1;
						break;
					}
				} 
			}
			if (g == 0)
			{
				t = j;
				break;
			}
		}
		if (t == -1)
		{
			m++;
			t = m;
			l[t] = len;
			for (j = 0 ; j <= len ; j++) 
			{
				a[t][j] = b[j];
			}
		}
		cin >> k;
		c = getchar();
		for (j = 1 ; j <= k ; j++)
		{
			len = 0;
			c = getchar();
			while ('0' <= c && c <= '9')
			{
				b[len] = c;
				len++;
				c = getchar();
			}
			b[len] = '\0';
			lq[t]++;
			llq[t][lq[t]] = len;
			for (h = 0 ; h <= len ; h++)
			{
				q[t][lq[t]][h] = b[h];
			}
		}
	}
	cout << m << "\n";
	for (i = 1 ; i <= m ; i++)
	{
		cout << a[i] << " ";
		for (j = 1 ; j <= lq[i] ; j++)
		{
			for (k = 1 ; k <= lq[i] ; k++)
			{
				if (j != k && llq[i][j] <= llq[i][k])
				{
					g = 0;
					for (h = 0 ; h <= llq[i][j] ; h++)
					{
						if (q[i][j][h] != q[i][k][llq[i][k]-llq[i][j]+h])
						{
							g = 1;
							break;
						}
					}
					if (!g) 
					{
						if (llq[i][j] != llq[i][k]) f[i][j] = 1;
						else 
						{
							if (j < k) f[i][j] = 1; 
						}
					}
				}
			}
		}
		mm = 0;
		for (j = 1 ; j <= lq[i] ; j++)
		{
			if (!f[i][j]) mm++;
		}
		cout << mm;
		for (j = 1 ; j <= lq[i] ; j++)
		{
			if (!f[i][j]) cout << " " << q[i][j];
		}
		cout << "\n";
	}
	//system("PAUSE");
	return 0;
}