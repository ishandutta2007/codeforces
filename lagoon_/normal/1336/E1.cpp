#include<bits/stdc++.h>
#define re register
const int mod=998244353,B=26;
long long a[200100],fk[110],fl[110],ff[110];
int nm[(1<<18)+1],bl[110],C[110][110];
int ppc(re long long x){return nm[x>>36]+nm[(x>>18)%(1<<18)]+nm[x%(1<<18)];}
int main()
{
	re int n,m,cnt=0,xa=1;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(re int i=m-1;i>=0;i--)
	{
		re long long x=1ll<<i;
		for(re int j=cnt+1;j<=n;j++)if(a[j]&x){std::swap(a[j],a[cnt+1]);break;}
		if(!(a[cnt+1]&x))continue;
		cnt++;bl[i]=-1;
		for(re int j=1;j<=n;j++)if(j!=cnt&&(a[j]&x))a[j]^=a[cnt];
	}
	C[0][0]=1;
	for(re int i=1;i<=m;i++)
	{
		C[i][0]=1;
		for(re int j=0;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(re int i=1;i<=n-cnt;i++)xa=xa*2%mod;
	for(re int i=0;i<cnt;i++)fk[i]=a[cnt-i];
	for(re int i=1;i<(1<<18);i++)nm[i]=nm[i>>1]+(i&1);
	if(cnt<=B)
	{
		re long long x=0;
		for(re int i=0;i<(1<<cnt);i++)
		{
			ff[ppc(x)]++;
			x^=fk[0];
			for(re int j=0;i&(1<<j);j++)x^=fk[j+1];
		}
		for(re int i=0;i<=m;i++)ff[i]=ff[i]%mod*xa%mod;
		for(re int i=0;i<=m;i++)printf("%lld ",ff[i]);
	}
	else
	{
		xa=1;
		if(n>=m)for(re int i=1;i<=n-m;i++)xa=xa*2%mod;
		else for(re int i=1;i<=m-n;i++)xa=1ll*xa*((mod+1)/2)%mod;
		re int cc=0;
		for(re int i=0;i<m;i++)if(!bl[i])bl[i]=cc++;
		for(re int i=0;i<cnt;i++)
		{
			re long long xx=0;
			for(re int j=0;j<m;j++)if((fk[i]&(1ll<<j))&&bl[j]!=-1)xx|=(1ll<<bl[j]);
			fk[i]=xx;
		}
		for(re int i=0;i<m-cnt;i++)
		{
			fl[i]|=(1ll<<i);
			for(re int j=0;j<cnt;j++)if(fk[j]&(1ll<<i))fl[i]|=(1ll<<(m-j-1));
		}
		re long long x=0;
		for(re int i=0;i<(1<<(m-cnt));i++)
		{
			ff[ppc(x)]++;
			x^=fl[0];
			for(re int j=0;i&(1<<j);j++)x^=fl[j+1];
		}
		for(re int c=0;c<=m;c++)
		{
			re int pc=0;
			for(re int p=0;p<=m;p++)
			{
				for(re int i=std::max(c+p-m,0);i<=p&&i<=c;i++)
				{
					pc=(pc+1ll*((i&1)?(mod-ff[p]):ff[p])*C[p][i]%mod*C[m-p][c-i])%mod;
				}
			}
			pc=1ll*pc*xa%mod;
			printf("%d ",pc);
		}
	}
}