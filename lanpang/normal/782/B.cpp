#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n; 
double x[60001] , v[60001] , l , r , m , ma , mi;

int trying(double t)
{
	double a , b , a1 , b1;
	a = max(mi,x[1]-(v[1]*t));
	b = min(ma,x[1]+(v[1]*t));
	for (int i = 2 ; i <= n ; i++)
	{
		a1 = max(mi,x[i]-(v[i]*t));
		b1 = min(ma,x[i]+(v[i]*t));
		if (a1 > b || a > b1)
		    return 0;
		else
		{
			if ((a1 <= a && b1 >= b) || (a <= a1 && b >= b1))
			{
				if (a <= a1 && b >= b1)
				{
					a = a1;
					b = b1;
				}
			}
			else
			{
				if (a1 < b && b < b1)
				{
					a = a1;
				}
				else
				{
					b = b1;
				}
			}
		}    
	}
	if (b>=a)
		return 1;
	else
	    return 0;	
}

int main ()
{
	int i , j;
	cin >> n;
	ma = -1;
	mi = 1000000001;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%lf",&x[i]);
		if (ma < x[i])
		    ma = x[i];
		if (mi > x[i])
		    mi = x[i];    
	}
	r = -1;
	l = 1000000001;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%lf",&v[i]);
		l = min(l,min((ma-x[i])/v[i],fabs(x[i]-mi)/v[i]));
		r = max(r,max((ma-x[i])/v[i],fabs(x[i]-mi)/v[i]));
	}
	while ((r-l) > 0.0000001)
	{
		m = (l+r)/2;
		if (trying(m) == 0)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	printf("%.7lf\n",(l+r)/2);
	//system("PAUSE");
	return 0;
}