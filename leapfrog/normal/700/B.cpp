//
//
#include<bits/stdc++.h>
using namespace std;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[400005];
int n,et,head[200005],k,fg[200005];long long res=0;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x),fg[x]+=fg[e[i].to];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) res+=min(fg[e[i].to],k-fg[e[i].to]);
}
int main()
{
	read(n),read(k),k<<=1;
	for(int i=1,x;i<=k;i++) read(x),fg[x]++;
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	return dfs(1,0),printf("%lld\n",res),0;
}