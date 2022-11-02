//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[400005];
int et,head[200005],n,rt;long long a[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline long long sum() {long long s=0;for(int i=1;i<=n;i++) s+=a[i];return s;}
inline void dfs1(int x) {for(int i=head[x];i;i=e[i].nxt) dfs1(e[i].to),a[x]+=max(a[e[i].to],0ll);}
inline void dfs2(int x)
{
	for(int i=head[x];i;i=e[i].nxt) if(a[e[i].to]>0) dfs2(e[i].to);
	if(x<=n) printf("%d ",x);
	for(int i=head[x];i;i=e[i].nxt) if(a[e[i].to]<=0) dfs2(e[i].to);
}
int main()
{
	read(n),rt=n+1;for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,f;i<=n;i++) {read(f);if(~f) adde(f,i);else adde(rt,i);}
	return dfs1(rt),printf("%lld\n",sum()),dfs2(rt),putchar('\n'),0;
}