//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
struct edge{int to,w,nxt;}e[200005];int n,m,et,head[100005],dg[100005];
struct node{int a,b,c;}a[300005];int at,rt;
//It is guaranteed that all val numbers are pairwise different and even.
inline void Add(int x,int y,int z) {a[++at]=(node){x,y,z};}
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et,dg[x]++;}
inline int dfs(int x,int fa,int ds)
{
	int z=0,w=0;ll s=0;for(int i=head[x];i;i=e[i].nxt)
		if(e[i].to!=fa) (z?w:z)=dfs(e[i].to,x,e[i].w),s+=e[i].w;
	if(!ds) return z;else if(!z) return Add(x,rt,ds),x;
	return Add(z,w,(s-ds)/2),Add(z,rt,(ds-s)/2),Add(w,rt,(ds-s)/2),z;
}
inline void flush() {for(int i=1;i<=at;i++) printf("%d %d %d\n",a[i].a,a[i].b,a[i].c);}
int main()
{
	read(n);for(int i=1,x,y,w;i<n;i++) read(x),read(y),read(w),adde(x,y,w),adde(y,x,w);
	for(int i=1;i<=n;i++) if(dg[i]==2) return puts("NO"),0;else if(dg[i]==1) rt=i;
	return dfs(rt,0,0),printf("YES\n%d\n",at),flush(),0;
}