#include<bits/stdc++.h>
using namespace std;
int t;
bool f;
double d,del,p,a1,a2;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&d);
		if (d*d-4*d<0.00) 
		{
			printf("N\n");
			continue;
		}
		del=d*d-4*d;
		p=sqrt(del);
		a1=(d+p)/2.00;a2=(d-p)/2.00;
		if (a1>=0.00 && a1<=d)
		{
			printf("Y %.9lf %.9lf\n",a1,d-a1);
		}
		else if (a2>=0.00 && a2<=d)
		{
			printf("Y %.9lf %.9lf\n",a2,d-a2);
		}
		else printf("N\n");
	}
	return 0;
}