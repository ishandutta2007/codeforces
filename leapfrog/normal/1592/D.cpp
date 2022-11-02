#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...dl) {read(x),read(dl...);}/*}}}*/
struct edge{int to,nxt;}e[10005];int et,head[10005];
int n,id[10005],dt,f[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	id[++dt]=x,f[x]=fa;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x);
}
inline int ask(int x)
{
	if(x==1) return -114514;
	printf("? %d",x);for(int i=1;i<=x;i++) printf(" %d",id[i]);
	putchar('\n'),fflush(stdout);int gg;read(gg);return gg;
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	dfs0(1,0);int l=1,r=n,rs=0,vl=ask(n);
	while(l<=r)
	{
		int md=(l+r)>>1;
		if(ask(md)==vl) rs=md,r=md-1;else l=md+1;
	}return printf("! %d %d\n",id[rs],f[id[rs]]),fflush(stdout),0;
}