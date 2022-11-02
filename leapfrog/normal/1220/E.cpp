//
#include<bits/stdc++.h>
using namespace std;const long long P=998244353;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[400005];
int n,m,s,w[200005],dg[200005],et,head[200005];long long F[200005],res=0,mx=0;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,dg[x]++;}
int main()
{
	read(n),read(m);if(n==1) return read(w[1]),printf("%d\n",w[1]),0;
	queue<int>q;for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),adde(y,x);
	read(s);for(int i=1;i<=n;i++) if(dg[i]==1&&i!=s) q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop(),dg[x]=0;
		for(int i=head[x];i;i=e[i].nxt)
		{
			F[e[i].to]=max(F[x]+w[x],F[e[i].to]);
			if(dg[e[i].to]&&e[i].to!=s&&--dg[e[i].to]==1) q.push(e[i].to);
		}
	}
	for(int i=1;i<=n;i++) if(dg[i]) mx=max(mx,F[i]),res+=w[i];
	return printf("%lld\n",res+mx),0;
}