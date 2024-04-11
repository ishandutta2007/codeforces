#include<bits/stdc++.h>
#define re register
struct eg{int to,v0,v1;eg*nx;}e[200100],*la[100100],*cnt=e;
inline void addE(re int a,re int b,re int v0,re int v1)
{
	*++cnt=(eg){b,v0,v1,la[a]};la[a]=cnt;
	*++cnt=(eg){a,v1,v0,la[b]};la[b]=cnt;
}
bool vis[100100],v0[100100],v1[100100],vk[2];
int d[100100],f[100100][2][2][2],ans[2],ans1[2],vvk0,vvk1;
const int mod=1e9+7;
void dfs(re int a)
{
	re int to=0,vv0,vv1;
	vis[a]=1;
	for(re eg*i=la[a];i;i=i->nx)if(!vis[i->to])
	{
		dfs(i->to);
		to=i->to;vv0=i->v0;vv1=i->v1;
	}else vvk0=i->v0,vvk1=i->v1;
	for(re int i1=0;i1<=1;i1++)vk[i1]=(v0[a]*i1)^(v1[a]*(!i1));
	if(to==0)
	{
		f[a][vk[0]][0][0]=f[a][vk[1]][1][1]=1;
	}
	else
	{
		for(re int i1=0;i1<=1;i1++)
			for(re int i2=0;i2<=1;i2++)
				for(re int i3=0;i3<=1;i3++)
					for(re int i4=0;i4<=1;i4++)
					{
						f[a][i1^((i2^vv1)|(i4^vv0))^vk[i4]][i4][i3]=(f[a][i1^((i2^vv1)|(i4^vv0))^vk[i4]][i4][i3]+f[to][i1][i2][i3])%mod;
					}
		/*for(re int i1=0;i1<=1;i1++)
			for(re int i2=0;i2<=1;i2++)
				for(re int i3=0;i3<=1;i3++)printf("**a**%d %d\n",a,f[a][i1][i2][i3]);*/
	}
}
int main()
{
	re int n,m,x,y,k;
	scanf("%d%d",&m,&n);
	ans[0]=1;
	for(re int i=1;i<=m;i++)
	{
		scanf("%d",&k);
		if(k==2)
		{
			scanf("%d%d",&x,&y);
			addE(abs(x),abs(y),x<0,y<0);
			d[abs(x)]++;d[abs(y)]++;
		}else {scanf("%d",&x);if(x<0)v1[-x]^=1;else v0[x]^=1;}
	}
	for(re int i=1;i<=n;i++)if(!vis[i]&&d[i]<=1)
	{
		dfs(i);
		ans1[0]=ans[0];ans1[1]=ans[1];ans[0]=ans[1]=0;
		for(re int i2=0;i2<=1;i2++)
			for(re int i3=0;i3<=1;i3++)
			{
				ans[0]=(ans[0]+1ll*ans1[0]*f[i][0][i2][i3]+1ll*ans1[1]*f[i][1][i2][i3])%mod;
				ans[1]=(ans[1]+1ll*ans1[1]*f[i][0][i2][i3]+1ll*ans1[0]*f[i][1][i2][i3])%mod;
			}
		//printf("***%d %d %d\n",i,ans[0],ans[1]);
	}
	for(re int i=1;i<=n;i++)if(!vis[i])
	{
		dfs(i);
		ans1[0]=ans[0];ans1[1]=ans[1];ans[0]=ans[1]=0;
		for(re int i2=0;i2<=1;i2++)
			for(re int i3=0;i3<=1;i3++)
			{
				ans[0]=(ans[0]+1ll*ans1[0]*f[i][(vvk0^i2)|(vvk1^i3)][i2][i3]+1ll*ans1[1]*f[i][((vvk0^i2)|(vvk1^i3))^1][i2][i3])%mod;
				ans[1]=(ans[1]+1ll*ans1[1]*f[i][(vvk0^i2)|(vvk1^i3)][i2][i3]+1ll*ans1[0]*f[i][((vvk0^i2)|(vvk1^i3))^1][i2][i3])%mod;
			}
		//printf("**2**%d %d %d\n",i,ans[0],ans[1]);
	}
	printf("%d\n",ans[1]);
}