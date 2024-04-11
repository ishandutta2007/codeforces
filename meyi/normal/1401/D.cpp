#include<bits/stdc++.h>
using namespace std;
#define ri register int
const int maxm=6e4+10,maxn=1e5+10,mod=1e9+7;
typedef long long ll;
struct edge{
	int to,nxt;
	ll cnt;
	inline edge(int to_=0,int nxt_=0,ll cnt_=0):to(to_),nxt(nxt_),cnt(cnt_){}
	inline bool operator<(const edge &k)const{
		return cnt>k.cnt;
	}
}e[maxn<<1];
int hd[maxn],len,m,n,sz[maxn],t;
ll ans,p[maxm];
inline void addedge(int fr,int to){
	e[++len]=edge(to,hd[fr]);
	hd[fr]=len;
}
void dfs(int now,int f){
	sz[now]=1;
	for(ri i=hd[now];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs(e[i].to,now);
			e[i].cnt=1ll*sz[e[i].to]*(n-sz[e[i].to]);
			sz[now]+=sz[e[i].to];
		}
}
inline bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(e,0,sizeof e);
		memset(hd,0,sizeof hd);
		memset(p,0,sizeof p);
		memset(sz,0,sizeof sz);
		ans=len=0;
		scanf("%d",&n);
		for(ri i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			addedge(a,b),addedge(b,a);
		}
		dfs(1,0);
		sort(e+1,e+len+1);
		scanf("%d",&m);
		for(ri i=1;i<=m;++i)scanf("%lld",p+i);
		sort(p+1,p+m+1,cmp);
		if(m>=n){
			int tmp=m-n+2;
			for(ri i=2;i<=tmp;++i)p[i]=p[i]*p[i-1]%mod;
			for(ri i=1,j=tmp;i<n;++i,++j)ans=(ans+(e[i].cnt%mod)*p[j]%mod)%mod;
			printf("%lld\n",ans);
		}
		else{
			for(ri i=1;i<=m;++i)ans=(ans+(e[i].cnt%mod)*p[i]%mod)%mod;
			for(ri i=m+1;i<n;++i)ans=(ans+(e[i].cnt%mod))%mod;
			printf("%lld\n",ans);
		}
	}
	return 0;
}