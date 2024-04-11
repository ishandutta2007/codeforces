#include<bits/stdc++.h>
#define re register
long long a[30],num[(1<<20)+1];
int f[(1<<20)+1],g[(1<<20)+1],lg[(1<<20)+1],ppc[(1<<20)+1];
int main()
{
	re int n,ans=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++){scanf("%lld",&a[i]);if(a[i]==0)n--,i--;}
	lg[0]=-1;
	for(re int i=1;i<(1<<n);i++)
	{
		lg[i]=lg[i/2]+1;
		num[i]=num[i^(1<<lg[i])]+a[lg[i]+1];
		ppc[i]=ppc[i/2]+(i&1);
		for(re int S=i^(1<<lg[i]),j=S;j;j=(j-1)&S)
		{
			if((num[j]-num[i-j])>-ppc[i]&&(num[j]-num[i-j])<ppc[i]&&((num[j]-num[i-j])&1)!=(ppc[i]&1)){g[i]=1;break;}
		}
	}
	for(re int i=0;i<(1<<n)-1;i++)
	{
		if(f[i]>ans)ans=f[i];
		re int S=((1<<n)-1)^i;
		if(f[i+(1<<lg[S])]<f[i])f[i+(1<<lg[S])]=f[i];
		for(re int j=S;j>=(1<<lg[S]);j=(j-1)&S)
		{
			if(g[j]&&f[i]>=f[i+j])f[i+j]=f[i]+1;
		}
	}
	if(f[(1<<n)-1]>ans)ans=f[(1<<n)-1];
	printf("%d\n",n-ans);
}