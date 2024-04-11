#include<bits/stdc++.h>
#define re register
const int mod=1e9+7;
int a[500100],ex[500100];
int pr[10001000],miu[10010000],pri[1001000],v[10010000],q[110],cnt;
int main()
{
	miu[1]=1;
	re int num=0;
	for(re int i=2;i<=1e7;i++)
	{
		if(!pr[i])pr[i]=i,pri[++cnt]=i,miu[i]=-1;
		for(re int j=1;j<=cnt&&i*pri[j]<=1e7;j++)
		{
			pr[i*pri[j]]=pri[j];
			if(!(i%pri[j]))break;
			miu[i*pri[j]]=-miu[i];
		}
	}
	re int n,ta;
	scanf("%d",&n);
	ex[0]=1;
	for(re int i=1;i<=n;i++)
	{
		ex[i]=ex[i-1]*2%mod;
		ta=0;
		scanf("%d",&a[i]);
		for(re int j=a[i];j!=1;)
		{
			q[++ta]=pr[j];
			for(j/=q[ta];pr[j]==q[ta];j/=q[ta]);
		}
		for(re int j=0;j<(1<<ta);j++)
		{
			re int vv=1;
			for(re int i1=1;i1<=ta;i1++)if((j>>i1-1)&1)vv*=q[i1];//printf("******%d\n",vv);
			num=(num+1ll*miu[vv]*ex[v[vv]]+mod)%mod;
			v[vv]++;
		}
	}
	re int ans=0;
	for(re int i=1;i<=n;i++)
	{
		ta=0;
		for(re int j=a[i];j!=1;)
		{
			q[++ta]=pr[j];
			for(j/=q[ta];pr[j]==q[ta];j/=q[ta]);
		}
		for(re int j=0;j<(1<<ta);j++)
		{
			re int vv=1;
			for(re int i1=1;i1<=ta;i1++)if((j>>i1-1)&1)vv*=q[i1];
			ans=(ans+1ll*miu[vv]*ex[v[vv]]+mod)%mod;//printf("***%d %d %d %d\n",vv,v[vv],miu[vv],ex[v[vv]-1]);
		}
		ans=(ans-num+mod)%mod;
		//printf("**************%d %d\n",i,ans);
	}
	printf("%d\n",ans);
}