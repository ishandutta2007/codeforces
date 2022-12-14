#include<bits/stdc++.h>
using namespace std;
int n,p[111],mxp;
double q[111],pre,ans,cur[111],mx;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	for (int i=1;i<=n;i++)
	{
		q[i]=(double)(100-p[i])/100.00;
	}
	pre=1.00;
	for (int i=1;i<=n;i++) pre*=(1.00-q[i]);
	ans=pre*(double)n;
	for (int i=1;i<=n;i++) cur[i]=q[i];
	for (int i=n+1;i<=500000;i++)
	{
		mx=-1e9;
		for (int j=1;j<=n;j++)
		{
			if (mx<pre/(1.00-cur[j])*(1.00-cur[j]*q[j])) 
			{
				mxp=j;
				mx=pre/(1.00-cur[j])*(1.00-cur[j]*q[j]);
			}
		}
		ans+=((mx-pre)*(double)i);
		pre=mx;
		cur[mxp]*=q[mxp];
	}
	printf("%.9lf\n",ans);
	return 0;
}