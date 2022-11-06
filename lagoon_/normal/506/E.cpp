#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define re register
#define ui unsigned int
const ui mod=10007;
int h,f[211][211][211];
char ss[210];
struct squ
{
	ui x[410][410];
	void operator *=(const squ&A)
	{
		ui c[h+1][h+1];memset(c,0,sizeof(c));
		for(re int i=1;i<=h;i++)
			for(re int j=1;j<=i;j++)if(x[j][i])
				for(re int k=i;k<=h;k++)if(A.x[i][k])
					c[j][k]=(c[j][k]+x[j][i]*A.x[i][k])%mod;
		for(re int i=1;i<=h;i++)for(re int j=1;j<=h;j++)x[i][j]=c[i][j];
	}
}jz,jz1,jz2;
squ ex(re squ a,re int b)
{
	re squ res;
	for(re int i=1;i<=h;i++)res.x[i][i]=1;
	for(;b;b>>=1,a*=a)if(b&1)res*=a;
	return res;
}
int main()
{
	re int n,m,mi=-1,mx,nm,ans=0;
	scanf("%s%d",ss+1,&m);
	n=strlen(ss+1);m+=n;nm=(m+1)>>1;
	for(re int j=n;j;j--)
	{
		for(re int k=j;k<=n;k++)
		{
			re int i=k-j+1;
			for(re int i1=0;i1<=n;i1++)
			{
				if(ss[j]==ss[k])f[j][k][i1]=i<=2?(i1==0):f[j+1][k-1][i1];
				else f[j][k][i1]=i1>0?(f[j+1][k][i1-1]+f[j][k-1][i1-1])%mod:0;
			}
		}
	}
	for(re int i=0;i<=n;i++)
	{
		if(f[1][n][i])
		{
			mx=i;
			if(mi==-1)mi=i;
		}
	}re int mx2=(n-mi+1)>>1;
	for(re int i=1;i<=mx;i++)jz.x[i][i]=24,jz.x[i][i+1]=1;
	for(re int i=mx+1;i<=mx+mx2;i++)
	{
		jz.x[i][i]=25,jz.x[i][i+mx2]=1;if(i!=mx+mx2)jz.x[i][i+1]=1;
	}
	for(re int i=mx+mx2+1;i<=mx+2*mx2;i++)jz.x[i][i]=26;
	h=mx+2*mx2;
	jz1=ex(jz,nm-1);jz2=jz1;jz2*=jz;
	for(re int i=mi;i<=mx;i++)
	{
		if(nm-i-(n-i+1)/2<0)continue;
		ans=(ans+jz2.x[mx-i+1][(n-i+1)/2+mx+mx2]*f[1][n][i])%mod;
		if((m&1)&&(!((n-i)&1)))ans=(ans-(jz1.x[mx-i+1][mx+(n-i+1)/2]*f[1][n][i])%mod+mod)%mod;
	}printf("%d",ans);
}