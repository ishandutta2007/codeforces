#include<bits/stdc++.h>
using namespace std;
#define re register
int x[15],y[15],r[15],bl[15],cnt;
long double xx[110],yy[110];
long double dis(re int i,re int j)
{
	return sqrtl((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int main()
{
	re int n,S=0,bb=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d%d%d",&x[i],&y[i],&r[i]);
	for(re int i=1;i<=n;i++)
	{
		for(re int j=i+1;j<=n;j++)
		{
			re long double d=dis(i,j);
			if(d>=r[i]-r[j]&&d>=r[j]-r[i]&&d<=r[i]+r[j])
			{
			
				bl[i]=bl[j]=1;
				re long double x1=2*(x[j]-x[i]),y1=2*(y[j]-y[i]),r1=(x1*x1+y1*y1)/4+r[i]*r[i]-r[j]*r[j];
				re long double d2=x1*x1+y1*y1,x0=x1*r1/d2+x[i],y0=y1*r1/d2+y[i],md=r[i]*r[i]*d2-r1*r1;
				y1*=sqrt(md)/d2,x1*=sqrt(md)/d2;//printf("**%d %d %Lf %Lf\n",i,j,x1,y1);
				if(x1<=1e-9F&&x1>=-1e-9F&&y1<=1e-9F&&y1>=-1e-9F)
				{
					S++;
					xx[++cnt]=x0+y1;yy[cnt]=y0-x1;
				}else
				{
					S+=2;
					xx[++cnt]=x0+y1;yy[cnt]=y0-x1;
					xx[++cnt]=x0-y1;yy[cnt]=y0+x1;
				}
				
			}
		}
		if(!bl[i])bb++;
	}
	re int nm=0;
	if(bb==0)S+=2;
	else if(bb==n)S+=n+1;
	else if(bb==1)S+=3;
	for(re int i=1;i<=cnt;i++)
	{
		for(re int j=i+1;j<=cnt;j++)
		if(xx[i]>=xx[j]-1e-9F&&xx[i]<=xx[j]+1e-9F&&yy[i]>=yy[j]-1e-9F&&yy[i]<=yy[j]+1e-9F){
			nm++;
		}
	}printf("%d\n",S-nm/3);
}