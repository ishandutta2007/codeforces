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
int n,m,a[200005],sm=0,st[400005];char v[200005];
struct edge{int to,w,nxt;}e[400005];int et=1,head[200005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline int dfs(int x,int ls)
{
	v[x]=1;int tot=a[x];for(int i=head[x];i;i=e[i].nxt)
		if(!v[e[i].to]) tot-=dfs(e[i].to,i);
	return st[ls>>1]=e[ls].w*tot,-tot;
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),sm+=a[i];
	read(m);for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y,1),adde(y,x,-1);
	if(sm) return puts("Impossible"),0;else puts("Possible");
	dfs(1,0);for(int i=1;i<=m;i++) printf("%d\n",st[i]);
	return 0;
}