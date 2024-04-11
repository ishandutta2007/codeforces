#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int a[maxn],m,n,siz[maxn],son[maxn],t_case;
void dfs1(int p,int f){
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
		}
	if(!son[p])son[p]=p;
	son[p]=son[son[p]];
}
multiset<int>s[maxn];
void dfs2(int p,int f){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			dfs2(e[i].to,p);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f&&son[e[i].to]!=son[p]){
			for(ri j:s[son[e[i].to]])s[son[p]].insert(j);
			s[son[e[i].to]].clear();
		}
	if(son[p]==p)s[p].insert(0);
	ri tmp=*s[son[p]].begin();
	s[son[p]].erase(s[son[p]].begin());
	s[son[p]].insert(tmp-1);
}
int cnt;
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(ri i:s[son[1]])a[++cnt]=-i;
	for(ri i=1;i<=n;++i)a[i]+=a[i-1];
	ll ans=LLONG_MIN;
	for(ri r=0;r<=m;++r){
		ri b=min(n-a[r],n>>1);
		ckmax(ans,1ll*(n-r-b)*(r-b));
	}
	printf("%lld",ans);
	return 0;
}