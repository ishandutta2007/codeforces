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
struct edge{int to,nxt;}e[1000005];int n,et,head[500005],dg[500005],L[500005],R[500005],lmr;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,dg[x]++;}
inline void dfs(int x,int fa)
{
	int cnt=1;lmr+=dg[x]+!fa;R[x]=lmr;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) L[e[i].to]=R[x]-cnt++,dfs(e[i].to,x);
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	L[1]=1,lmr=1,dfs(1,0);for(int i=1;i<=n;i++) printf("%d %d\n",L[i],R[i]);
}