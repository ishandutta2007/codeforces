#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
double dp[1048576];
double x[105],y[105],a[105];
int main()
{
	int n,l,r;
	n=read();
	l=read();
	r=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&x[i],&y[i],&a[i]);
	}
	dp[0]=(double)l;
	double now;
	for(int i=1;i<(1<<n);i++)
	{
		dp[i]=(double)l;
		for(int j=1;j<=n;j++)
		{
			if((i&(1<<(j-1)))==0)continue;
			now=dp[i^(1<<(j-1))];
			if(now>x[j])
			{
				double jd=(atan((now-x[j])/y[j]));
				jd+=a[j]/180.0*3.14159265358;
				if(jd>=3.14159265358/2)
				{
					//printf("%d %.9lf\n",i,dp[i]);
					//printf("%.9lf %.9lf %.9lf\n",x[j],y[j],dp[i^(1<<(j-1))]);
					printf("%.9lf\n",(double)(r-l));
					return 0;
				}
				now=y[j]*tan(jd)+x[j];
				//printf("%d %.9lf\n",i^(1<<(j-1)),dp[i^(1<<(j-1))]);
				//printf("%.9lf %.9lf %.9lf %.9lf\n",now,x[j],y[j],dp[i^(1<<(j-1))]);
				if(now>r)
				{
					printf("%.9lf\n",(double)(r-l));
					return 0;
				}
				dp[i]=max(dp[i],now);
			}
			else
			{
				double jd=(atan((now-x[j])/y[j]));
				jd+=a[j]/180.0*3.14159265358;
				if(jd>=3.14159265358/2)
				{
					printf("%.9lf\n",(double)(r-l));
					return 0;
				}
				now=y[j]*tan(jd)+x[j];
				//printf("%.9lf %.9lf %.9lf %.9lf\n",now,x[j],y[j],dp[i^(1<<(j-1))]);
				if(now>r)
				{
					printf("%.9lf\n",(double)(r-l));
					return 0;
				}
				dp[i]=max(dp[i],now);
			}
		}
	}
	//for(int j=0;j<=(1<<n)-1;j++)printf("%.9lf ",dp[j]);
	//printf("\n");
	printf("%.9lf\n",dp[(1<<n)-1]-l);
	return 0;
}