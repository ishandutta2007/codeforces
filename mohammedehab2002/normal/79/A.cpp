#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	int p100,p10,t,i,turn=3,c10;
	cin >> p100 >> p10;
	t=p100*100+p10*10;
	while (t>=220 && p10>=2)
	{
		if (turn%2)
		{
			p100-=min(2,p100);
			c10=220-min(2,p100)*100;
			p10-=c10/10;
			turn++;
			t-=220;
		}
		else
		{
			for (i=22;i>0;i-=10)
			{
				if (i<=p10)
				{
					p10-=i;
					c10=i*10;
					goto out;
				}
			}
			out: p100-=(220-i*10)/100;
			turn++;
			t-=220;
		}
	}
	if (turn%2)
	cout << "Hanako";
	else
	cout << "Ciel";
}