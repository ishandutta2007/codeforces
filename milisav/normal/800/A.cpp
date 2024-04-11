#include <bits\stdc++.h>
using namespace std;
struct l
{
	double a,b;
	double r;
};
double eb=1e-6;
double epsilon=1e-10;
double m=0,t=0;
int n;
double p;
l d[200000];
double a,b;
bool operator <(l x, l y)
{
	return x.r<y.r;
}
int main()
{
	scanf("%d %lf",&n,&p);
	for(int i=0;i<n;i++)
	{
		scanf("%lf %lf",&a,&b);
		d[i].a=a;
		d[i].b=b;
		d[i].r=b/a;
	}
	sort(d,d+n);
	double s=0;
	double e=0;
	for(int i=0;i<n;i++)
	{
		s+=d[i].a;
		e+=d[i].b;
		if(i==n-1)
		{
			if(p-s>-epsilon)
			{
				printf("-1");
				return 0;
			}
			else
			{
				printf("%.8lf",e/(s-p));
				return 0;
			}
		}
		else
		{
			if(e+(p-s)*d[i+1].r<epsilon)
			{
				printf("%.8lf",e/(s-p));
				return 0;
			}
		}
	}
	//printf("%.5lf",binary());
	return 0;
}