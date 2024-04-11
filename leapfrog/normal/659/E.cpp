#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[100005<<1];
int n,m,ans=0,tot=0,head[100005],x[100005],y[100005],v[100005],cp[100005],ce[100005];
inline void adde(int x,int y) {e[++tot]=(edge){y,head[x]},head[x]=tot;}
inline void dfs(int x)
{
	for(int i=head[x];i;i=e[i].nxt) if(v[e[i].to]!=v[x]) v[e[i].to]=v[x],dfs(e[i].to);
}
int main()
{
	scanf("%d%d",&n,&m),memset(head,0,sizeof(head)),memset(cp,0,sizeof(cp));
	for(int i=1;i<=m;i++) scanf("%d%d",x+i,y+i),adde(x[i],y[i]),adde(y[i],x[i]);
	for(int i=1;i<=n;i++) v[i]=i;
	for(int i=1;i<=n;i++) if(v[i]==i) dfs(i);
	for(int i=1;i<=n;i++) cp[v[i]]++;
	for(int i=1;i<=m;i++) ce[v[x[i]]]++;
	for(int i=1;i<=n;i++) if(v[i]==i) ans+=cp[i]>ce[i];
	return printf("%d\n",ans),0;
}