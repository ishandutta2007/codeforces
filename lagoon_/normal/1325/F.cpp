#include<bits/stdc++.h>
#define re register
struct eg{int to;eg*nx;}e[400100],*la[100100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
int ta,q[100100],dis[100100],dep[100100],B,fa[100100];
void dfs(re int a)
{
	for(re eg*i=la[a];i;i=i->nx)if(!fa[i->to])
	{
		dep[i->to]=dep[a]+1;fa[i->to]=a;dfs(i->to);dis[a]=std::max(dis[a],dis[i->to]-1);
	}
	else if(dep[i->to]<=dep[a]-B+1)
	{
		printf("2\n%d\n",dep[a]-dep[i->to]+1);
		while(a!=fa[i->to])
		{
			printf("%d ",a);a=fa[a];
		}
		puts("");exit(0);
	}
	if(dis[a]==0)dis[a]=B-1,q[++ta]=a;
}
int main()
{
	re int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++)scanf("%d%d",&x,&y),addE(x,y);
	B=(int)(sqrt(n)-0.5);
	while(B*B<n)B++;
	fa[1]=-1;dfs(1);
	printf("1\n");
	for(re int i=1;i<=B;i++)printf("%d ",q[i]);
}