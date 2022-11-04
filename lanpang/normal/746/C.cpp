#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int s , x1 , x2 , t1 , t2 , p , d;
int time , t , x , tt;

int main ()
{
	scanf("%d%d%d%d%d%d%d",&s,&x1,&x2,&t1,&t2,&p,&d);
	if (x1 > x2)
	{
		x1 = s-x1;
		x2 = s-x2;
		p = s-p;
		d = -d;
	}
	x = x2-x1;
	t = x*t2;
	if (d == -1)
	{
		time += (p+x1)*t1;
		p = x1;
	}
	if (t1 >= t2)
	    cout << t << "\n";
	else
	{  
				
		if (p >= x2)
		{
			time += (s*2-p+x1)*t1;
			p = x1;
		}
		tt = t1*(x2-p)+time;
		if (p > (x1+time/t2))
			tt += s*2*t1;
		cout << min(tt,t) << "\n";		
	}
    //system("PAUSE");
	return 0;
}