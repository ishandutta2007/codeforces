#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double d,r,n;
double x,y,ri,dis;
int ans;
int main()
{
	scanf("%lf%lf%lf",&r,&d,&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&x,&y,&ri);
		dis=sqrt(x*x+y*y);
		if (dis-ri>=r-d && dis+ri<=r) ans++;
	}
	printf("%d\n",ans);
	return 0;
}