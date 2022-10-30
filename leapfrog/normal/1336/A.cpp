#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[200005<<1];
struct node{int dep,siz;bool operator<(node b) const {return dep-siz>b.dep-b.siz;}}a[200005];
int n,k,tot=0,head[200005];long long ans=0;
inline void adde(int x,int y) {e[++tot]=(edge){y,head[x]},head[x]=tot;}
inline void dfs(int x,int fa)
{
	a[x].dep=a[fa].dep+1,a[x].siz=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x),a[x].siz+=a[e[i].to].siz;
}
int main()
{
	scanf("%d%d",&n,&k),a[0].dep=0;
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	dfs(1,0),sort(a+1,a+n+1);
	for(int i=1;i<=k;i++) ans+=a[i].dep-a[i].siz;
	return printf("%lld\n",ans),0;
}