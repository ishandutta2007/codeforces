#include<cstdio>
using namespace std;
double n,p,l[111111],r[111111],ans,s,es[111111],ues[111111];
int nei1,nei2;
double getres(double le,double ri)
{
	int x,y;
	double dx,dy;
	x=(le-1)/p;
	y=ri/p;
	dx=(double) x;
	dy=(double) y;
	return dy-dx;
}
int main()
{
	scanf("%lf%lf",&n,&p);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&l[i],&r[i]);
		s=getres(l[i],r[i]);
		es[i]=s/(double)(r[i]-l[i]+1);
		ues[i]=(double)1-es[i];
	}
	for (int i=1;i<=n;i++)
	{
		nei1=i+1;
		if (nei1==n+1) nei1=1;
		nei2=i-1;
		if (nei2==0) nei2=n;
		ans=ans+es[i]*(double)(2000.00+1000.00*(ues[nei1]+ues[nei2]));
	}
	printf("%lf",ans);
	return 0;
}