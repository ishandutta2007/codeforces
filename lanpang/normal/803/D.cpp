#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , k , f[1000001] , nn;
char a[1000001] , aa;

int mmp(int h)
{
	int c , p , x , y , i;
	c = 0;
	p = 0;
	y = 0;
	for (i = 1 ; i <= nn ; i++)
	{
		x = f[i]-c;
		if (y+x > h)
		{
			p++;
			y = x;
			if (p >= k)
			{
				return 1;
			}
		}
		else
		{
			y += x;
		}
		c = f[i];
	}
	return 0;
}

int main ()
{
	int i , l , r , m , ma;
	cin >> k;
	aa = getchar();
	gets(a);
	n = strlen(a);
	nn = 0;
	for (i = 0 ; i < n ; i++)
	{
		if (a[i] == ' ' || a[i] == '-')
		{
			nn++;
			f[nn] = i+1;
			if (nn == 1)
			{
				ma = f[nn];
			}
			else
			{
				if (ma < f[nn]-f[nn-1])
				{
					ma = f[nn]-f[nn-1];
				}
			}
		}
	}
	nn++;
	f[nn] = n;
	if (nn == 1 || ma < f[nn]-f[nn-1])
	    ma = f[nn]-f[nn-1];
	l = ma;
	r = n;
	while (l < r)
	{
		m = (l+r)/2;
		if (mmp(m) == 1)
		{
			if (l != m)
				l = m;
			else
			    l = m+1;	
		}
		else
		{
			r = m;
		}
	}
	cout << l << "\n";
	//system("PAUSE");
	return 0;
}