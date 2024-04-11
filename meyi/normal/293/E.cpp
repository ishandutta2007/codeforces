#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
bool vis[maxn];
int mx[maxn],rt,siz[maxn],tot;
void calc_siz(int p,int f){
	mx[p]=0;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to]&&e[i].to!=f){
			calc_siz(e[i].to,p);
			ckmax(mx[p],siz[e[i].to]);
			siz[p]+=siz[e[i].to];
		}
	ckmax(mx[p],tot-siz[p]);
	if(mx[p]<mx[rt])rt=p;
}
int dep[maxn],dis[maxn],l,w;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>v;
void calc_dis(int p,int f){
	if(dep[p]>l||dis[p]>w)return;
	v.emplace_back(dis[p],dep[p]);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to]&&e[i].to!=f){
			dep[e[i].to]=dep[p]+1,dis[e[i].to]=dis[p]+e[i].v;
			calc_dis(e[i].to,p);
		}
}
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(++k;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		T ret=0;
		for(ckmin(++k,mx_idx);k>0;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<ll>t;
ll ans;
inline void calc_ans(int p,int len1,int len2,int sign){
	dep[p]=len1,dis[p]=len2;
	v.clear();
	calc_dis(p,0);
	sort(v.begin(),v.end());
	t.mx_idx=siz[p]+1;
	t.clear();
	ll ret=0;
	for(auto i:v)t.add(i.se,1);
	for(ri i=0,j=(int)v.size()-1;i<j;++i){
		t.add(v[i].se,-1);
		while(j>i&&v[i].fi+v[j].fi>w)t.add(v[j].se,-1),--j;
		ret+=t.query(l-v[i].se);
	}
	ans+=ret*sign;
}
void dfs(int p){
	vis[p]=true;
	calc_ans(p,0,0,1);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to]){
			calc_ans(e[i].to,1,e[i].v,-1);
			rt=0,tot=siz[e[i].to];
			calc_siz(e[i].to,0);
			dfs(rt);
		}
}
int n;
int main(){
	scanf("%d%d%d",&n,&l,&w);
	for(ri i=2,x,y;i<=n;++i){
		scanf("%d%d",&x,&y);
		addedge(i,x,y),addedge(x,i,y);
	}
	mx[0]=INT_MAX,tot=n;
	calc_siz(1,0);
	dfs(rt);
	printf("%lld",ans);
	return 0;
}