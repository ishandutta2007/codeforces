//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[400005];int et,head[200005];
int n,m,K,vs[200005],st[400005],tt=0;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x)
{
	st[++tt]=x;
	for(int i=head[x];i;i=e[i].nxt) if(!vs[e[i].to]) vs[e[i].to]=1,dfs(e[i].to),st[++tt]=x;
}
int main()
{
	read(n),read(m),read(K);int qwq=(n*2+K-1)/K;
	for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),adde(y,x);
	vs[1]=1,dfs(1);for(int i=1,id=1;i<=K;i++,putchar('\n'))
	{
		if(id>tt) {printf("1 1");continue;}else printf("%d ",min(qwq,tt-id+1));
		for(int j=1;j<=qwq&&id<=tt;j++,id++) printf("%d ",st[id]);
	}
	return 0;
}