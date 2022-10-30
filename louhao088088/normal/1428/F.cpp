#include<bits/stdc++.h>
const int N=1e6+7;
long long n,f[N],now,ans, sum;
char s[N];
int main() 
{
	scanf("%lld%s",&n,s+1);
	for(int i=1;i<=n;i++)f[i]=n+1;
	for(int i=n;i>=1;i--) 
	{
		if(s[i]=='1')now++,sum+=f[now]-i;
		else while(now)f[now]=i+now,now--;ans+=sum; 
	}
	printf("%lld\n",ans);
	return 0;
}