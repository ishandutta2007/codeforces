#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=1010,maxn=210;
const ll inf=0x3f3f3f3f3f3f3f3fll;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int to,nxt,f,f_;
}e[maxm<<1];
int hd[maxn],len=1,tmp[maxn];
inline void addedge(int fr,int to,int f){
	e[++len]={to,hd[fr],f,f};
	hd[fr]=len;
	e[++len]={fr,hd[to],f,f};
	hd[to]=len;
}
int n,s,t;
ll dep[maxn];
inline bool bfs1(){
	clear(dep,n);
	dep[s]=1;
	queue<int>q;
	q.push(s);
	while(q.size()){
		ri p=q.front();q.pop();
		for(ri i=hd[p];i;i=e[i].nxt)
			if(e[i].f>0&&!dep[e[i].to])
				dep[e[i].to]=dep[p]+1,q.push(e[i].to);
	}
	return dep[t];
}
ll dfs(int p,ll lim){
	if(p==t)return lim;
	ll sum=0;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].f>0&&dep[p]+1==dep[e[i].to]){
			ll f=dfs(e[i].to,min(lim-sum,(ll)e[i].f));
			if(f){
				e[i].f-=f,e[i^1].f+=f;
				sum+=f;
				if(sum==lim)break;
			}
		}
	if(!sum)dep[p]=0;
	return sum;
}
inline ll dinic(){
	for(ri i=2;i<=len;++i)e[i].f=e[i].f_;
	ll ret=0;
	while(bfs1()){
		ret+=dfs(s,inf);
		memcpy(hd,tmp,n+1<<1);
	}
	return ret;
}
ll ans;
typedef pair<ll,int> pli;
#define fi first
#define se second
vector<pli>g[maxn];
void build(const vector<int> &v){
	if(v.size()<2)return;
	s=v.front(),t=v.back();
	ll f=dinic();
	ans+=f;
	g[s].emplace_back(f,t),g[t].emplace_back(f,s);
	vector<int>l,r;
	for(ri i:v)(dep[i]?l:r).push_back(i);
	build(l),build(r);
}
bool vis[maxn];
inline void bfs2(){
	priority_queue<pli,vector<pli>,less<pli>>q;
	q.push({0,1});
	while(q.size()){
		ri p=q.top().se;q.pop();
		printf("%d ",p);
		vis[p]=true;
		for(auto &i:g[p])
			if(!vis[i.se])
				q.push(i);
	}
}
int m,q,t_case;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		ri x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
	}
	memcpy(tmp,hd,n+1<<1);
	vector<int>v;
	for(ri i=1;i<=n;++i)v.push_back(i);
	build(v);
	printf("%lld\n",ans);
	bfs2();
	return 0;
}