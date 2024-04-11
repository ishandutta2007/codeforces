#include<bits/stdc++.h>
#define re register
#define lb long long
struct eg{int to;eg*nx;}e[1001000],*la[250100],*la1[250100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
inline void addE1(re int a,re int b)
{
	*++cnt=(eg){b,la1[a]};la1[a]=cnt;
	*++cnt=(eg){a,la1[b]};la1[b]=cnt;
}
int top[300100],fa[300100][20],dep[300100],ff[300100],hv[300100],dfn[300100],sz[300100],tot;
int fd(re int a){return ff[a]==a?a:ff[a]=fd(ff[a]);}
void dfs(re int a)
{
	sz[a]=1;
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa[a][0])
	{
		fa[i->to][0]=a;dep[i->to]=dep[a]+1;
		dfs(i->to);sz[a]+=sz[i->to];if(sz[hv[a]]<sz[i->to])hv[a]=i->to;
	}
}
void dfs1(re int a)
{dfn[a]=++tot;
	if(hv[a])top[hv[a]]=top[a],dfs1(hv[a]);
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa[a][0]&&i->to!=hv[a])
	{
		top[i->to]=i->to;dfs1(i->to);
	}
}
int find(re int a,re int b)
{
	a=fd(a);b=fd(b);
	for(re int i=19;i>=0;i--)if(dep[fd(fa[a][i])]>dep[b])a=fd(fa[a][i]);
	return fd(fa[a][0])==b?a:b;
}
void dfs2(re int a,re int fa1)
{
	for(re eg*i=la1[a];i;i=i->nx)if(i->to!=fa1)
	{
		dfs2(i->to,a);
	}
	if(fa1)
	{
		re int b=fd(find(fa1,a));
		printf("%d %d %d %d\n",b,fa[b][0],a,fa1);
		ff[b]=fa[b][0];
	}
}
int main()
{
	re int n,x,y;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)ff[i]=i;
	for(re int i=1;i<n;i++)scanf("%d%d",&x,&y),addE(x,y);
	for(re int i=1;i<n;i++)scanf("%d%d",&x,&y),addE1(x,y);
	dep[1]=1;dfs(1);top[1]=1;dfs1(1);
	for(re int i=1;i<=19;i++)for(re int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
	printf("%d\n",n-1);
	dfs2(1,0);
}