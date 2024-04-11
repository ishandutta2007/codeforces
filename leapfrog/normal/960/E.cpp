//Coded by Kamiyama_Shiki on 2021.11.10 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005,P=1e9+7;int n,a[N],s[N],t[N],sz[N],rs=0;
struct edge{int to,nxt;}e[N<<1];int et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	sz[x]=1,s[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs0(e[i].to,x),s[x]-=s[e[i].to],sz[x]+=sz[e[i].to];
		rs=(rs+1ll*(P-s[e[i].to])*(n-sz[e[i].to])%P*a[x])%P;
	}
}
inline void dfs1(int x,int fa)
{
	if(fa) t[x]=-(s[fa]+s[x])-t[fa];else t[x]=0;
	rs=(rs+1ll*t[x]*sz[x]%P*a[x])%P;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),a[i]=(a[i]+P)%P;
	for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) rs=(rs+1ll*a[i]*n)%P;
	return dfs0(1,0),dfs1(1,0),printf("%d\n",(rs+P)%P),0;
}