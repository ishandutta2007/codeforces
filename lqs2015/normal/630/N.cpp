#include<cstdio>
#include<cmath>
using namespace std;
double a,b,c,x,xx,y,yy;
int main()
{
	scanf("%lf%lf%lf",&a,&b,&c);
	x=(-b+sqrt(b*b-4*a*c))/(2*a);
	y=(-b-sqrt(b*b-4*a*c))/(2*a);
	if (x>y) printf("%lf\n%lf\n",x,y);
	else printf("%lf\n%lf\n",y,x);
	return 0;
}