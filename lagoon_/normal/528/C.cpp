#include<bits/stdc++.h>
#define re register
struct eg{int to;eg*nx;}e[1001000],*la[500100],*cnt=e+1;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
int d[500100],sta[500100],ta;
bool vis[500100];
void dfs(re int a)
{
	for(;la[a];la[a]?la[a]=la[a]->nx:0)if(!vis[(la[a]-e)/2])
	{
		vis[(la[a]-e)/2]=1;
		dfs(la[a]->to);
	}
	sta[++ta]=a;
}
int main()
{
	re int n,m,x,y,qw=0;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++)
		scanf("%d%d",&x,&y),addE(x,y),d[x]++,d[y]++;
	for(re int i=1;i<=n;i++)if(d[i]&1){if(qw)m++,addE(qw,i),qw=0;else qw=i;}
	if(m&1)addE(1,1),m++;
	dfs(1);
	printf("%d\n",m);
	for(re int i=1;i<ta;i++)
	{
		if(i&1)printf("%d %d\n",sta[i],sta[i+1]);
		else printf("%d %d\n",sta[i+1],sta[i]);
	}
}