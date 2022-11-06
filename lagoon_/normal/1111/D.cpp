#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
#define re register
#define ui unsigned int
#define ull unsigned long long
#pragma GCC optimize(2)
const ui mod=1000000007,mod1=2000000014;
ui ca[200],ans[60][60],jx[100100],jx1[100100],c[60],f[100100],g[100100];
char s[100100];
ui ex(re ui a,re ui b)
{
	re ui an=1;for(;b;b>>=1,a=(ull)a*a%mod)if(b&1)an=(ull)an*a%mod;return an;
}
ui gcd(ui a,ui b){return b?gcd(b,a%b):a;}
int main()
{
	for(re ui i=0;i<=25;i++)ca['A'+i]=i;
	for(re ui i=0;i<=25;i++)ca['a'+i]=i+26;
	scanf("%s",s+1);f[0]=1;
	re ui n=strlen(s+1),x,y,x1,y1,q,x2,y2,xx;
	for(re ui i=1;i<=n;i++)c[ca[s[i]]]++;jx[0]=1;
	for(re ui i=1;i<=(n>>1);i++)jx[i]=(ull)jx[i-1]*i%mod;jx1[n>>1]=ex(jx[n>>1],mod-2);
	for(re ui i=n>>1;i;i--)jx1[i-1]=(ull)jx1[i]*i%mod;
	re ui w=(ull)jx[n>>1]*jx[n>>1]%mod,w1;
	for(re ui i=0;i<=51;i++)if(c[i])
	{
		x=c[i];
		w=(ull)w*jx1[x]%mod;
		for(re ui i=n>>1;i>=x;i--)(f[i]+=f[i-x])>=mod?f[i]-=mod:0;
	}w1=(ull)w*f[n>>1]%mod;
	scanf("%d",&q);
	for(re int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		if(s[x]==s[y]){printf("%u\n",w1);continue;}
		x2=ca[s[x]],y2=ca[s[y]];
		if(ans[x2][y2]){printf("%u\n",ans[x2][y2]-1);continue;}
		x=c[x2],y=c[y2];
		if(x+y>(n>>1)){puts("0");continue;}if(x>y)x1=x,x=y,y=x1;
		x1=gcd(x,y);y1=(n>>1)-x-y;xx=y1%x1;
		for(re ui i=0;i<x;i+=x1)g[i+xx]=f[i+xx];
		for(re ui i=y1%x1+x;i<=y1;i+=x1)(g[i]=f[i]+(mod-(int)g[i-x]))>=mod?g[i]-=mod:0;
		for(re ui i=y1%x1+y;i<=y1;i+=x1)
		{
			(g[i]+=(mod-(int)g[i-y]))>=mod?g[i]-=mod:0;
		}
		printf("%u\n",(ans[x2][y2]=(((ull)g[y1]*w)<<1)%mod+1)-1);
	}
}