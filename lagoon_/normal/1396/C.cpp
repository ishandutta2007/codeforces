#include<bits/stdc++.h>
#define re register
int aa[1001000];
long long f[3],g[3],f1[3],g1[3];
int main()
{
	re int n,d,r1,r2,r3;
	scanf("%d%d%d%d%d",&n,&r1,&r2,&r3,&d);
	for(re int j1=0;j1<=2;j1++)f[j1]=g[j1]=1ll<<60;
	f[0]=-d;
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&aa[i]);
		g[0]=1ll<<60;
		re long long c1=std::min(1ll*r2,1ll*r1*(aa[i]+1))+std::min(r1,std::min(r2,r3)),c0=1ll*r1*aa[i]+r3;
		for(re int j1=0;j1<=2;j1++)f1[j1]=g1[j1]=1ll<<60;
		for(re int i1=0;i1<=2;i1++)
			for(re int j1=0;j1<=2;j1++)
			{
				f1[j1]=std::min(f1[j1],f[i1]+d*2ll*j1+d+c0);
				if(i1+j1>=1)f1[j1]=std::min(f1[j1],f[i1]+d*2ll*j1+d+c1);
				if(i1+j1>=1)g1[j1]=std::min(g1[j1],g[i1]+d*2ll*j1+c0);
				if(i1+j1>=2)g1[j1]=std::min(g1[j1],g[i1]+d*2ll*j1+c1);
			}
		for(re int j1=0;j1<=2;j1++)f[j1]=f1[j1],g[j1]=std::min(f1[j1],g1[j1]);
	}
	printf("%lld\n",g[0]);
}