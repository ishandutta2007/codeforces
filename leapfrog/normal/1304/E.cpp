//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[200005];
int n,m,et,head[100005],f[100005][25],dep[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x][0]=fa;
	for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;~i;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;~i;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
inline int dis(int a,int b) {return dep[a]+dep[b]-(dep[LCA(a,b)]<<1);}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs(1,0),read(m);
	for(int a,b,x,y,k;m--;)
	{
		read(x),read(y),read(a),read(b),read(k);
		int A=dis(a,b),B=dis(a,x)+dis(b,y)+1,C=dis(a,y)+dis(b,x)+1;
//		printf("%d , %d , %d\n",A,B,C);
		if(min(A,min(B,C))>k) {puts("NO");continue;}
		if((A<=k&&!((k-A)&1))) {puts("YES");continue;}
		if((B<=k&&!((k-B)&1))) {puts("YES");continue;}
		if((C<=k&&!((k-C)&1))) {puts("YES");continue;}
		puts("NO");
	}
	return 0;
}