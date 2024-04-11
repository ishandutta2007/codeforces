#include<bits/stdc++.h>
using namespace std;
#define ri register int
const int maxn=1e5+10;
struct edge{
	int fr,to,v;
};
vector<edge>e;
int m,maxp,n,s;
vector<int>hd[maxn*10];
inline void addedge1(int fr,int to,int v){
	hd[fr].push_back(e.size());
	e.push_back({fr,to,v});
}
struct segment_tree{
	int l,r;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
void build1(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		maxp=max(maxp,p);
		return;
	}
	int mid=l+r>>1;
	build1(ls(p),l,mid);
	build1(rs(p),mid+1,r);
}
void build2(int p){
	if(t[p].l==t[p].r){
		addedge1(p+n,t[p].l,0);
		addedge1(t[p].l,p+n+maxp,0);
		return;
	}
	addedge1(p+n,ls(p)+n,0);
	addedge1(ls(p)+n+maxp,p+n+maxp,0);
	addedge1(p+n,rs(p)+n,0);
	addedge1(rs(p)+n+maxp,p+n+maxp,0);
	build2(ls(p));
	build2(rs(p));
}
void addedge2(int p,int l,int r,int v,int w){
	if(l>t[p].r||t[p].l>r)return;
	if(l<=t[p].l&&t[p].r<=r){
		addedge1(v,p+n,w);
		return;
	}
	addedge2(ls(p),l,r,v,w);
	addedge2(rs(p),l,r,v,w);
}
void addedge3(int p,int l,int r,int v,int w){
	if(l>t[p].r||t[p].l>r)return;
	if(l<=t[p].l&&t[p].r<=r){
		addedge1(p+n+maxp,v,w);
		return;
	}
	addedge3(ls(p),l,r,v,w);
	addedge3(rs(p),l,r,v,w);
}
typedef long long ll;
ll dis[maxn*10];
bool vis[maxn*10];
struct node{
	ll d;
	int p;
	inline bool operator<(const node &k)const{
		return d>k.d;
	}
};
priority_queue<node>q;
const ll inf=0x3f3f3f3f3f3f3f3fll;
inline void dijkstra(){
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		int now=q.top().p;q.pop();
		if(vis[now])continue;
		vis[now]=true;
		for(ri i=0;i<hd[now].size();++i){
			int id=hd[now][i];
			if(dis[now]+e[id].v<dis[e[id].to]){
				dis[e[id].to]=dis[now]+e[id].v;
				if(!vis[e[id].to])q.push({dis[e[id].to],e[id].to});
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	build1(1,1,n);
	build2(1);
	while(m--){
		int op,v,l,r,w;
		scanf("%d%d%d%d",&op,&v,&l,&r);
		if(op==1)addedge1(v,l,r);
		else if(op==2)scanf("%d",&w),addedge2(1,l,r,v,w);
		else scanf("%d",&w),addedge3(1,l,r,v,w);
	}
	dijkstra();
	for(ri i=1;i<=n;++i)printf("%lld ",dis[i]==inf?-1:dis[i]);
	return 0;
}