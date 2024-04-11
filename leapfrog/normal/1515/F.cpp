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
int n,m,X,le,ri,rs[300005];ll sm,a[300005];char v[300005];
struct edge{int to,w,nxt;}e[600005];int et,head[300005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void solve(int x,int fa,int ls)
{
	v[x]=1;for(int i=head[x];i;i=e[i].nxt) if(!v[e[i].to]) solve(e[i].to,x,e[i].w);
	if(x==1) return;else if(a[x]>=X) a[fa]+=a[x]-X,rs[++le]=ls;else rs[--ri]=ls;
}
int main()
{
	read(n),read(m),read(X),le=0,ri=n;
	for(int i=1;i<=n;i++) read(a[i]),sm+=a[i];
	for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y,i),adde(y,x,i);
	if(sm<1ll*(n-1)*X) return puts("NO"),0;
	solve(1,0,0);if(le+1!=ri) return puts("NO"),0;else puts("YES");
	for(int i=1;i<n;i++) printf("%d\n",rs[i]);
	return 0;
}