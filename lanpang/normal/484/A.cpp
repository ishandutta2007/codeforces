#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long l , r , a[100] , na , ca , b[100] , nb , cb , nc , c[100] , ans;
int t , T;

void mmp()
{
	long long t=1;
	ans = 0;
	for (int i = 1 ; i <= nc ; i++)
	{
		if (i > 1)
			t*=2;
		ans += t*c[i];
	}
}

int main ()
{
	int i , k , h;
	cin >> T;
	for (t = 1 ; t <= T ; t++)
	{
		cin >> l >> r;
		ca = 1;
		na = 0;
		while (l != 0)
		{
			na++;
			a[na] = l%2;
			if (a[na] == 0)
			    ca = 0;
			l/=2;
		}
		cb = 1;
		nb = 0;
		while (r != 0)
		{
			nb++;
			b[nb] = r%2;
			if (b[nb] == 0)
			    cb = 0;
			r/=2;
		}
		if (cb == 1)
		{
			nc = nb;
			for (i = 1 ; i <= nc ; i++)
			{
				c[i] = 1;
			}
		}
		else
		{
			if (nb > na)
			{
				nc = nb-1;
				for (i = 1 ; i <= nc ; i++)
				{
					c[i] = 1;
				}
			}
			else
			{
				nc = nb;
				i = nb;
				while (a[i] == b[i] && i >= 1)
				{
					c[i] = a[i];
					i--;
				}
				if (i >= 1)
				{
					h = i;
					k = 1;
					for (i = h ; i >= 1 ; i--)
					{
						if (b[i] == 0)
						{
							k = 0;
						}
					}
					if (k == 0)
					{
						c[h] = 0;
						h--;
					}
					for (i = h ; i >= 1 ; i--)
					{
						c[i] = 1;
					}
				}
			}
		}
		mmp();
		cout << ans << "\n";
	}
    //system("PAUSE");
	return 0;
}