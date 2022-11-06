#include<bits/stdc++.h>
#define re register
long long ans;
struct eg{int to;eg*nx;}e[400100],*la[200100],*cnt=e;
void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
int fa[200100],bb;
int a[200100],b[200100],dep[200100],q[200100];
bool v1[200100],v2[200100];
void dfs(re int a)
{
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa[a])
	{
		fa[i->to]=a;dep[i->to]=dep[a]+1;dfs(i->to);
	}
}
int main()
{
	re int n,rt,a1,x,y,xx,x1,x2,ta=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);if(a[i]==0)a1=i;
	}
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);if(b[i]==0)rt=i;
	}
	for(re int i=1;i<n;i++)scanf("%d%d",&x,&y),addE(x,y);
	dfs(rt);ans=dep[a1];
	for(;a1;a1=fa[a1])std::swap(a[a1],a[fa[a1]]),v2[a1]=1;x=0;
	for(re int i=1;i<=n;i++)if(a[i]!=b[i]&&!v1[i]&&dep[i]>dep[x])x=i;x1=y=x;
	if(!x){printf("0 %lld\n",ans);return 0;}
	for(;a[y]!=b[y];y=fa[y])q[++ta]=y,v1[y]=1;
	std::reverse(q+1,q+ta+1);x=0;
	for(re int i=1;i<=n;i++)if(a[i]!=b[i]&&!v1[i]&&dep[i]>dep[x])x=i;x2=x?x:y;
	for(;a[x]!=b[x];x=fa[x])q[++ta]=x,v1[x]=1;
	if(x&&x!=y)puts("-1"),exit(0);x=y;
	for(re int i=1;i<=n;i++)if(a[i]!=b[i]&&!v1[i])puts("-1"),exit(0);
	if(!v2[q[1]])std::reverse(q+1,q+ta+1);
	for(xx=1;a[q[1]]!=b[q[xx+1]];xx++);
	for(re int i=1;i<=ta;i++)if(a[q[i]]!=b[q[(i+xx-1)%ta+1]])puts("-1"),exit(0);
	for(y=1;y<=ta&&v2[q[y]];y++);y--;
	ans+=std::min((long long)(ta+1)*xx,(long long)(ta+1)*(ta-xx)-2*y);
	for(;!v2[x];x=fa[x]) ans+=2;
	printf("%d %d %lld\n",std::min(x1,x2),std::max(x1,x2),ans);
}