#include<bits/stdc++.h>
#define re register
int f[100100][2],ans,d[100100];
struct eg{int to;eg*nx;}e[200100],*la[100100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
void dfs(re int a,re int fa)
{
	f[a][0]=d[a];f[a][1]=1;
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)
	{
		dfs(i->to,a);
		ans=std::max(ans,std::max(std::max(f[a][0]+f[i->to][0]-2,f[a][0]+f[i->to][1]-1),f[a][1]+f[i->to][0]-1));
		f[a][0]=std::max(f[a][0],std::max(f[i->to][0]+d[a]-2,f[i->to][1]+d[a]-1));
		f[a][1]=std::max(f[a][1],f[i->to][0]);
	}
}
int main()
{
	re int n,x,y;
	scanf("%d",&n);
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		addE(x,y);d[x]++;d[y]++;
	}
	dfs(1,0);
	printf("%d\n",ans);
}