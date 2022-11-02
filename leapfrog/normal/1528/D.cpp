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
struct edge{int to,w,nxt;}e[360005];int et,head[605],n,m,d[605];char v[605];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dijk(int s)
{
	memset(d,0x3f,sizeof(d)),memset(v,0,sizeof(v));
	for(int i=head[s];i;i=e[i].nxt) d[e[i].to]=e[i].w;
	for(int g=1;g<n;g++)
	{
		int x=0;for(int i=1;i<=n;i++) if(!v[i]&&d[x]>=d[i]) x=i;
		v[x]=1,d[x%n+1]=min(d[x]+1,d[x%n+1]);
		for(int i=head[x],y;i;i=e[i].nxt) y=(e[i].to+d[x]-1)%n+1,d[y]=min(d[x]+e[i].w,d[y]);
	}
	for(int i=1;i<=n;i++) printf("%d%c",s==i?0:d[i],i==n?'\n':' ');
}
int main()
{
	read(n),read(m);
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),adde(++x,++y,w);
	for(int i=1;i<=n;i++) dijk(i);
	int _=0;return (0^_^0);
}