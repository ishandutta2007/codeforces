//Coded by Kamiyama_Shiki on 2021.11.07 {{{
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
const int N=1000005;
struct edge{int to,nxt;}e[N<<1];int et,head[N],n,K,dg[N],rs;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,dg[x]++;}
inline int dfs(int x,int fa)
{
	if(dg[x]==1) return 1;
	int nw=0;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		{int v=dfs(e[i].to,x);if(nw+v>K) rs++,nw=min(nw,v);else nw=max(nw,v);}
	return nw?nw+1:0;
}
int main()
{
	read(n,K);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	int rt=0;for(int i=1;i<=n;i++) if(dg[i]>1) rt=i;
	int v;return v=dfs(rt,0),printf("%d\n",!!v+rs),0;
}