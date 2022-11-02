#include<bits/stdc++.h>
using namespace std;
int n,len,x[1005],b[1005],pre[1005],out[1005];double dp[1005],l,r;
inline bool chck(double ans)
{
	for(int i=1;i<=n;i++)
	{
		dp[i]=1e30;
		for(int j=0;j<i;j++)
		{
			double t=dp[j]+sqrt(1e-8+abs(x[i]-x[j]-len))-ans*b[i];
			if(dp[i]>t) dp[i]=t,pre[i]=j;
		}
	}
	return dp[n]<0;
}
int main()
{
	scanf("%d%d",&n,&len),l=0,r=1e10;
	for(int i=1;i<=n;i++) scanf("%d%d",x+i,b+i);
	while(r-l>1e-8) {double mid=(l+r)/2;if(chck(mid)) r=mid;else l=mid;}
	chck(l),len=0,out[0]=n;
	while(pre[out[len]]) out[len+1]=pre[out[len]],len++;
	for(int i=len;i>=0;i--) printf("%d%c",out[i],(i==0)?'\n':' ');
	return 0;
}