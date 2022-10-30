//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int L,R,n,m,ml=1e9,mr,l[100005],r[100005],cl[100005];
struct edge{int to,nxt;}e[200005];int et,head[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void FAIL() {puts("IMPOSSIBLE"),exit(0);}
inline void dfs(int x)
{
	for(int i=head[x];i;i=e[i].nxt)
		if(!~cl[e[i].to]) cl[e[i].to]=cl[x]^1,dfs(e[i].to);
		else if(cl[e[i].to]==cl[x]) FAIL();
}
int main()
{
	read(L),read(R),read(n),read(m);
	for(int i=1;i<=n;i++) read(l[i]),read(r[i]),mr=max(mr,l[i]),ml=min(ml,r[i]);
	memset(cl,-1,sizeof(cl));if(ml+mr<L) mr=L-ml;else if(ml+mr>R) ml=R-mr;
	if(ml<0||mr<0) FAIL();else for(int i=1;i<=n;i++)
	{
		char can1=l[i]<=ml&&ml<=r[i],can2=l[i]<=mr&&mr<=r[i];
		if(!can1&&!can2) return FAIL(),0;else if(!can1) cl[i]=1;else if(!can2) cl[i]=0;
	}
	for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) if(~cl[i]) dfs(i);
	for(int i=1;i<=n;i++) if(!~cl[i]) cl[i]=0,dfs(i);
	puts("POSSIBLE"),printf("%d %d\n",ml,mr);
	for(int i=1;i<=n;i++) printf("%d",cl[i]+1);
	return putchar('\n'),0;
}