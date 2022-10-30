//
#include<bits/stdc++.h>
using namespace std;const int P=998244353;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,we,nxt;}e[500005];
int n,m,et,head[500005],col[500005],dis[500005],vis[500005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
int main()
{
	read(n),read(m);queue<int>q;q.push(n);if(n==1) return puts("0\n0"),0;
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),adde(y,x,w);
	memset(col,-1,sizeof(col)),vis[n]=1;int tag=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();if(x==1) {tag=1;break;}
		for(int i=head[x];i;i=e[i].nxt) if(!vis[e[i].to])
		{
			if(col[e[i].to]==-1||col[e[i].to]==1-e[i].we) col[e[i].to]=1-e[i].we;
			else q.push(e[i].to),dis[e[i].to]=dis[x]+1,vis[e[i].to]=1;
		}
	}
	if(tag) printf("%d\n",dis[1]);else puts("-1");
	for(int i=1;i<=n;i++) printf("%d",col[i]==-1?0:col[i]);
	return putchar('\n'),0;
}