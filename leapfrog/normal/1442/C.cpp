//Coded by Kamiyama_Shiki on 2021.11.08 {{{
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
const int N=400005,P=998244353;int n,m;
struct edge{int to,nxt;}e[N<<1];int et,head[N];ll ds[N][19],dd[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
struct ${int x,k;ll w;char operator<($ b) const {return w>b.w;}};
struct _{int x;ll w;char operator<(_ b) const {return w>b.w;}};
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n,m);for(int i=1,x,y;i<=m;i++) read(x,y),adde(x<<1,y<<1),adde(y<<1|1,x<<1|1);
	priority_queue<$>q;memset(ds,0x3f,sizeof(ds)),q.push(($){2,0,ds[2][0]=0});
	while(!q.empty())
	{
		$ t=q.top();q.pop();int x=t.x,k=t.k;if(t.w!=ds[x][k]) continue;
		if(x==(n<<1)||x==(n<<1|1)) return printf("%lld\n",t.w),0;else if(t.k==18) continue;
		if(ds[x^1][k+1]>ds[x][k]+(1<<k)) q.push(($){x^1,k+1,ds[x^1][k+1]=ds[x][k]+(1<<k)});
		for(int i=head[x];i;i=e[i].nxt) if(ds[e[i].to][k]>t.w+1) q.push(($){e[i].to,k,ds[e[i].to][k]=t.w+1});
	}
	priority_queue<_>p;memset(dd,0x3f,sizeof(dd)),p.push((_){2,dd[2]=0});
	while(!p.empty())
	{
		_ t=p.top();p.pop();int x=t.x;if(dd[x]!=t.w) continue;
		if(dd[x^1]>dd[x]+10000000) p.push((_){x^1,dd[x^1]=dd[x]+10000000});
		for(int i=head[x];i;i=e[i].nxt) if(dd[e[i].to]>t.w+1) p.push((_){e[i].to,dd[e[i].to]=t.w+1});
	}
	ll rs=min(dd[n<<1],dd[n<<1|1]);
	return printf("%lld\n",(ksm(2,rs/10000000)-1+rs%10000000)%P),0;
}