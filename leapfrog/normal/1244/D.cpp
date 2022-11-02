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
const int N=100005;int n,c[N][4],cl[N],et,head[N],id[N],it,dg[N];struct edge{int to,nxt;}e[N<<2];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,dg[x]++;}
inline void dfs(int x,int f=0) {id[++it]=x;for(int i=head[x];i;i=e[i].nxt) if(e[i].to^f) dfs(e[i].to,x);}
int main()
{
	read(n);for(int i=1;i<4;i++) for(int j=1;j<=n;j++) read(c[j][i]);
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	ll mn=1e18;for(int i=1;i<=n;i++) if(dg[i]>2) return puts("-1"),0;
	int a,b;for(int i=1;i<=n;i++) if(dg[i]==1) {dfs(i);break;}
	for(int p=1;p<=3;p++) for(int q=1;q<=3;q++) if(p^q)
	{
		cl[id[1]]=p,cl[id[2]]=q;for(int i=3;i<=n;i++) cl[id[i]]=cl[id[i-1]]^cl[id[i-2]];
		ll sm=0;for(int i=1;i<=n;i++) sm+=c[i][cl[i]];
		if(sm<mn) mn=sm,a=p,b=q;
	}
	cl[id[1]]=a,cl[id[2]]=b;for(int i=3;i<=n;i++) cl[id[i]]=cl[id[i-1]]^cl[id[i-2]];
	printf("%lld\n",mn);for(int i=1;i<=n;i++) printf("%d%c",cl[i],i==n?'\n':' ');
	return 0;
}