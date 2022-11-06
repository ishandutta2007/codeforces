#include<bits/stdc++.h>
using namespace std;
#define re register
int phi[1001000],pri[100100],cnt;
int main()
{
	re int n,k;
	re long long ans=2;
	scanf("%d%d",&n,&k);
	if(k==1){puts("3");return 0;}
	for(re int i=2;i<=n;i++)
	{
		if(!phi[i])phi[i]=i-1,pri[++cnt]=i;
		for(re int j=1;j<=cnt&&i*pri[j]<=n;j++)
		{
			if(!(i%pri[j])){phi[i*pri[j]]=phi[i]*pri[j];break;}
			else phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
	sort(phi+3,phi+n+1);
	for(re int i=1;i<=k;i++)ans+=phi[i+2];
	printf("%lld\n",ans);
}