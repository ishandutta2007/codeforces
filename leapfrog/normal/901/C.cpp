//Coded by leapfrog on 2021.11.04 {{{
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
const int N=300005;int n,m,Q;vector<int>vc[N];
int cl[N],clt,tot[N],rs[N],cnt[N],dep[N];ll qz[N];
struct edge{int to,nxt;}e[N<<1];int et,head[N],f[N];char vs[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	vs[x]=1,f[x]=fa,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt)
		if(!vs[e[i].to]) dfs(e[i].to,x);
		else if(e[i].to!=fa&&dep[e[i].to]<dep[x]) vc[x].push_back(e[i].to);
}
int main()
{
	read(n,m);for(int i=1,x,y;i<=m;i++) read(x,y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) if(!vs[i]) dfs(i,0);
	//for(int i=1;i<=n;i++) printf("%d%c",f[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++) for(int y:vc[i])
	{
		int x=i;tot[++clt]=1,cl[y]=clt;
		//printf("%d %d\n",x,y);
		while(x!=y) cl[x]=clt,tot[clt]++,x=f[x];
	}
	//for(int i=1;i<=n;i++) printf("%d%c",cl[i],i==n?'\n':' ');
	for(int i=1,l=1;i<=n;i++)
	{
		if(!cl[i]) {rs[i]=l;continue;}else cnt[cl[i]]++;
		while(cnt[cl[i]]==tot[cl[i]]) cnt[cl[l]]--,l++;
		rs[i]=l;
	}
	//for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+rs[i];
	int Q;read(Q);for(int l,r;Q--;)
	{
		read(l,r);int res=l-1;//<=
		for(int L=l,R=r,md=(L+R)>>1;L<=R;md=(L+R)>>1)
			if(rs[md]<=l) res=md,L=md+1;else R=md-1;
		printf("%lld\n",1ll*(r-l+1)*(l+r+2)/2-(1ll*l*(res-l+1)+qz[r]-qz[res]));
		//printf("%d %d %d\n",l,res,r);
		//printf("debug %lld %lld\n",1ll*l*(res-l+1),qz[r]-qz[res]);
	}return 0;
}