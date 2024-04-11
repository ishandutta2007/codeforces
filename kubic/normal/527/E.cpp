#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 1000005
#define set(a,v) memset(a,v,sizeof(a)) 
int n,m,nw,dg[N];bool vs[M]; 
int cntE,hd[N],cur[N];struct Edge {int v,nxt;}e[M];
void addE(int u,int v) {e[cntE]=(Edge) {v,hd[u]};hd[u]=cntE++;}
void print(int x) {if(x>9) print(x/10);putchar(x%10+48);}
void dfs(int u)
{
	for(int i=cur[u],v;~i;i=cur[u])
	{
		cur[u]=e[i].nxt;if(vs[i]) continue;vs[i]=vs[i^1]=1;
		v=e[i].v;dfs(v);++nw;
		if(nw&1) print(u),putchar(' '),print(v),puts("");
		else print(v),putchar(' '),print(u),puts("");
	}
}
int main()
{
	set(hd,-1);scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d %d",&u,&v),addE(u,v),addE(v,u),++dg[u],++dg[v];
	for(int i=1,lst=0;i<=n;++i) if(dg[i]&1)
	{if(lst) addE(i,lst),addE(lst,i),lst=0,++m;else lst=i;}
	if(m&1) addE(1,1),addE(1,1),++m;for(int i=1;i<=n;++i) cur[i]=hd[i];
	printf("%d\n",m);dfs(1);return 0;
}