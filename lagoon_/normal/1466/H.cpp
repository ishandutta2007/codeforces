#include<bits/stdc++.h>
#define re register
int p[100100],c1[100100],vl[110][110],c[110][110],nw1[110],nw2[110],ff[2011][45],vc[45],n,vis[110];
const int mod=1e9+7;
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(re int i=1;i<=n;i++)
	if(!vis[i]){
		re int vv=0;
		for(re int j=i;!vis[j];j=p[j])
		{
			vv++;vis[j]=1;
		}
		c1[vv]++;
	}
	re int N=1;
	c[0][0]=1;
	for(re int i=1;i<=n;i++)
	{
		c[i][0]=1;
		for(re int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	for(re int i=1;i<=n;i++)
	{
		N*=c1[i]+1;
		vl[i-1][0]=1;
		for(re int j=0;j<i;j++)
		{
			re int fac=1;
			for(re int i1=i-j;i1<i;i1++)fac=1ll*fac*i1%mod;
			for(re int i1=1;i1<=n-j-1;i1++)fac=1ll*fac*i1%mod;
			vl[i-1][1]=(vl[i-1][1]+fac)%mod;
		}
		for(re int j=2;j<=n;j++)vl[i-1][j]=1ll*vl[i-1][1]*vl[i-1][j-1]%mod;
	}
	ff[0][0]=1;
	for(re int i=1;i<N;i++)
	{
		re int nn=1,nm1=0;
		for(re int j=1;j<=n;j++)
		{
			nw1[j]=(i/nn)%(c1[j]+1);
			nm1+=nw1[j]*j;
			nn*=c1[j]+1;
		}
		for(re int i1=0;i1<i;i1++)
		{
			nn=1;
			re int nm2=0,bl=1;
			for(re int j=1;j<=n;j++)
			{
				nw2[j]=(i1/nn)%(c1[j]+1);
				nm2+=nw2[j]*j;
				if(nw2[j]>nw1[j]){bl=0;break;}
				nn*=c1[j]+1;
			}
			if(!bl)continue;
			memset(vc,0,sizeof(vc));
			for(re int j=0;j<=nm2;j++)vc[nm1]=(vc[nm1]+1ll*ff[i1][j]*vl[j][nm1-nm2])%mod;
			for(re int j=1;j<=n;j++)vc[nm1]=1ll*vc[nm1]*c[nw1[j]][nw2[j]]%mod;
			for(re int j=1;j<=n;j++)
			{
				for(re int ii=nw1[j]-nw2[j];ii;ii--)
					for(re int i1=j;i1<=nm1;i1++)vc[i1-j]=(vc[i1-j]+(mod-vc[i1]))%mod;
			}
			for(re int i1=0;i1<=nm1;i1++)ff[i][i1]=(ff[i][i1]+vc[i1])%mod;
		}
	}
	printf("%d\n",ff[N-1][n]);
}