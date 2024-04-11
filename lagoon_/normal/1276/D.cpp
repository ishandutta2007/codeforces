#include<bits/stdc++.h>
using namespace std; 
#define re register
struct eg{int to,no;eg*nx;}e[400100],*la[201000],*cnt=e;
inline void addE(re int a,re int b,re int c)
{
	*++cnt=(eg){b,c,la[a]};la[a]=cnt;
	*++cnt=(eg){a,c,la[b]};la[b]=cnt;
}
const int mod=998244353;
int f[200100][3],n;
int x[200100],y[200100];
void dfs(re int a,re int fa,re int c)
{
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)dfs(i->to,a,i->no);
	if(c==-1)
	{
		re int x1=1,x0=0;
		for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)
		{
			re int xx1,xx0;
			xx0=((long long)x0*(f[i->to][0]+f[i->to][2])+(long long)x1*f[i->to][0])%mod;
			xx1=((long long)x1*f[i->to][1])%mod;
			x1=xx1;x0=xx0;
		}
		f[a][0]=x0;f[a][1]=x1;
	}
	else
	{
		re int x01=1,x00=0,x10=0,x11=0,x2=0;
		re eg*j=la[a];
		while(j&&j->to==fa)j=j->nx;
		if(((!j)||(j->no>c)))
		{
			x10=(x01+x00)%mod;x00=0;
		}
		for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)
		{
			re int xx1,xx0;
			xx0=((long long)x00*(f[i->to][0]+f[i->to][2])+(long long)x01*f[i->to][0])%mod;
			xx1=((long long)x01*f[i->to][1])%mod;
			x01=xx1;x00=xx0;
			xx0=((long long)x10*(f[i->to][0]+f[i->to][2])+(long long)x11*f[i->to][0])%mod;
			xx1=((long long)x11*f[i->to][1])%mod;
			x11=xx1;x10=xx0;
			x2=(long long)x2*(f[i->to][0]+f[i->to][2])%mod;
			re eg*j=i->nx;
			while(j&&j->to==fa)j=j->nx;
			if(i->no<c&&((!j)||(j->no>c)))
			{
				x10=(x01+x00)%mod;x2=x00;x00=0;
			}
		}
		f[a][0]=(x00+x01)%mod;f[a][1]=(x10+x11)%mod;f[a][2]=x2;
	}
}
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for(re int i=n-1;i;i--)addE(x[i],y[i],i);
	dfs(1,0,-1);
	printf("%d\n",(f[1][0]+f[1][1])%mod);
}