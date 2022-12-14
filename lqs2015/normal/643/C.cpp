#include<bits/stdc++.h>
using namespace std;
int n,k,la,nw;
double t[222222],sum[222222],summ[222222],sumf[222222],f[222222],dp[2][222222];
double slope(pair<double,double> x,pair<double,double> y)
{
	return (y.second-x.second)/(x.first-y.first);
}
pair<double,double> xx,yy,add;
deque<pair<double,double> > q;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lf",&t[i]);
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+(1.00/t[i]);
		summ[i]=summ[i-1]+t[i];
		f[i]=t[i]*sum[i-1];
		sumf[i]=sumf[i-1]+f[i];
	}
	nw=1;
	for (int i=1;i<=n;i++) dp[la][i]=1e18;
	for (int i=1;i<=k;i++)
	{
		q.clear();
		for (int j=1;j<=n;j++)
		{
			add=make_pair(-summ[j-1],sumf[j-1]+dp[la][j-1]);
			while(q.size()>1)
			{
				xx=q[(int)q.size()-1];yy=q[(int)q.size()-2];
				if (slope(yy,xx)>slope(xx,add)) q.pop_back();
				else break;
			}
			q.push_back(add);
			while(q.size()>1)
			{
				xx=q[0];yy=q[1];
				if (xx.first*sum[j]+xx.second>yy.first*sum[j]+yy.second) q.pop_front();
				else break;
			} 
			xx=q[0];
			dp[nw][j]=xx.first*sum[j]+xx.second+summ[j]*sum[j]-sumf[j];
		}
		la^=1;nw^=1;
	}
	printf("%.9lf\n",dp[la][n]);
	return 0;
}