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
struct edge{int to,nxt;}e[200005];
int T,n,et,a,b,da,db,head[100005],d[100005],mx,mw;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	d[x]=d[fa]+1;if(mx<d[x]) mx=d[x],mw=x;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x);
}
int main()
{
	for(read(T),d[0]=-1;T--;)
	{
		read(n),read(a),read(b),read(da),read(db),memset(head,0,sizeof(head)),et=0;
		for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
		if(db<=da+da) {puts("Alice");continue;}
		mx=0,dfs(b,0),mx=0,dfs(mw,0);
		if(mx<=da+da) {puts("Alice");continue;}
		dfs(b,0);if(d[a]<=da) puts("Alice");else puts("Bob");
	}
	return 0;
}