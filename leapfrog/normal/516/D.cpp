//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,w,nxt;}e[200005];int n,et,head[100005],res,Q;ll l;
ll ds[2][100005],F[100005];int cf[100005],tp;pair<ll,int>st[100005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dfs0(int x,int fa,ll *d) {for(int i=head[x];i;i=e[i].nxt) if(e[i].to^fa) d[e[i].to]=d[x]+e[i].w,dfs0(e[i].to,x,d);}
inline void dfs1(int x,int fa)
{
	st[++tp]=make_pair(F[x],x);int wh=upper_bound(st+1,st+tp+1,make_pair(F[x]-l,0))-st-1;
	//printf("%d : %d -> ",x,wh);for(int i=1;i<=tp;i++) printf("<%d,%d>%c",st[i].first,st[i].second,i==tp?'\n':' ');
	cf[x]++,cf[st[wh].second]--;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x),cf[x]+=cf[e[i].to];
	res=max(res,cf[x]),tp--;
}
int main()
{
	F[0]=1e18,read(n);for(int i=1,x,y,w;i<n;i++) read(x),read(y),read(w),adde(x,y,w),adde(y,x,w);
	ds[0][1]=0,dfs0(1,0,ds[0]);int s=0;for(int i=1;i<=n;i++) if(ds[0][s]<=ds[0][i]) s=i;
	ds[0][s]=0,dfs0(s,0,ds[0]);int t=0;for(int i=1;i<=n;i++) if(ds[0][t]<=ds[0][i]) t=i;
	ds[1][t]=0,dfs0(t,0,ds[1]);int rt=0;for(int i=1;i<=n;i++) if(F[rt]>=(F[i]=max(ds[0][i],ds[1][i]))) rt=i;
	//for(int i=1;i<=n;i++) printf("%d%c",F[i],i==n?'\n':' ');
	for(read(Q);Q--;) read(l),tp=res=0,memset(cf,0,sizeof(cf)),dfs1(rt,0),printf("%d\n",res);
	return 0;
}