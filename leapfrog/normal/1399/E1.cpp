#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{long long w;int sz;bool operator<(node b) const {return (w-w/2)*sz<(b.w-b.w/2)*b.sz;}};
struct edge{int to;long long w;int nxt;}e[200005];
int T,n,et,dep[100005],head[100005],sz[1000005];long long s,r;
priority_queue<node>q;
inline void adde(int x,int y,long long w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dfs(int x,int fa=0)
{
	int f=0;sz[x]=0;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) f=1,dep[e[i].to]=dep[x]+e[i].w,dfs(e[i].to,x),sz[x]+=sz[e[i].to],q.push((node){e[i].w,sz[e[i].to]});
	if(f==0) sz[x]=1,r+=dep[x];
}
signed main()
{
	for(scanf("%lld",&T);T--;)
	{
		scanf("%lld%lld",&n,&s),memset(head,0,sizeof(head)),et=0,r=0;
		while(!q.empty()) q.pop();
		for(int i=1,x,y,w;i<n;i++) scanf("%lld%lld%lld",&x,&y,&w),adde(x,y,w),adde(y,x,w);
		dep[1]=0,dfs(1);int cnt=0;
		while(r>s&&!q.empty())
		{
			node x=q.top();q.pop();cnt++;
			r-=1ll*(x.w-x.w/2)*x.sz;q.push((node){x.w/2,x.sz});
//			printf("%lld , %lld\n",x.w,x.sz);
		}
		printf("%lld\n",cnt);
	}
	return 0;
}