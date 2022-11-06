#include<bits/stdc++.h>
#define re register
struct eg{int to;eg*nx;}e[400100],*la[200100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
int d[200100],dep[200100],f1,g1;
void dfs(re int a,re int fa)
{
	if(dep[a])f1++;
	else g1++;
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)
	{
		dep[i->to]=!dep[a];
		dfs(i->to,a);
	}
}
int main()
{
	re int n,x,y,ans=0;
	scanf("%d",&n);
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		addE(x,y);d[x]++;d[y]++;
	}
	dfs(1,0);
	ans=std::min(f1,g1)-1;
	printf("%d\n",ans);
}