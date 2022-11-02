//Coded by Kamiyama_Shiki on 2021.11.12 {{{
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
const int N=200005;
struct edge{int to,nxt;}e[N<<1];int n,X,et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
int dep[N],mxd[N],f[N];
inline void dfs0(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x]=fa,mxd[x]=dep[x];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		dfs0(e[i].to,x),mxd[x]=max(mxd[x],mxd[e[i].to]);
}
int main()
{
	read(n,X);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	dfs0(1,0);for(int lim=(dep[X]-2)>>1;lim;lim--) X=f[X];
	return printf("%d\n",(mxd[X]-1)<<1),0;
}