#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define SZ(k) k.size()
#define ALL(k) k.begin(),k.end()
#define DEBUG(k...) fprintf(stderr,k)
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chkmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct dsu{
	int fa[maxn];
	inline void init(int siz){for(ri i=1;i<=siz;++i)fa[i]=i;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
}d;
int m,n;
vector<int>ans,hd[maxn];
vector<pii>e;
bool vis[maxn];
inline int other(int id,int k){
	return e[id].fi^e[id].se^k;
}
int dfs(int p){
	vector<int>tmp;
	while(hd[p].size()){
		ri now=hd[p].back();hd[p].pop_back();
		if(vis[now])continue;
		vis[now]=true;
		ri mch=dfs(other(now,p));
		if(mch)ans.pb(p),ans.pb(other(now,p)),ans.pb(mch);
		else tmp.pb(now);
	}
	while(tmp.size()>1){
		ri x=tmp.back();tmp.pop_back();
		ri y=tmp.back();tmp.pop_back();
		ans.pb(other(x,p)),ans.pb(p),ans.pb(other(y,p));
	}
	return tmp.size()?other(tmp.back(),p):0;
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		hd[x].pb(e.size()),hd[y].pb(e.size());
		e.eb(x,y);
	}
	for(ri i=1;i<=n;++i)dfs(i);
	printf("%d\n",SZ(ans)/3);
	for(ri i=0;i<SZ(ans);++i)printf("%d%c",ans[i],i%3==2?10:32);
	return 0;
}