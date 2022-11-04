#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=9e5+9, M=5e6+9; //2+ 

struct edge {int to,nxt,w;}e[M]; int hd[N],tot;
void add(int u,int v,int w) {e[++tot]=(edge){v,hd[u],w};hd[u]=tot;}

int n,q,s;

struct Node {int l,r;}t[N];
void build(int p,int l,int r) {
	t[p].l=l, t[p].r=r;
	if(l==r) {
		add(l+8*n,p,0), add(p+4*n,l+8*n,0);
		add(p,l+8*n,0), add(l+8*n,p+4*n,0);
		return;
	}
	add(p,p*2,0), add(p*2+n*4,p+n*4,0);
	add(p,p*2+1,0), add(p*2+1+n*4,p+n*4,0);
	build(p*2,l,(l+r)/2), build(p*2+1,(l+r)/2+1,r);
}
void addh(int p,int x,int y,bool type,int u,int w) {
	int l=t[p].l, r=t[p].r, mid=((l+r)>>1);
	if(l==x&&y==r) {
		if(!type) return add(u+8*n,p,w);
		else return add(p+4*n,u+8*n,w);
	}
	if(y<=mid) addh(p*2,x,y,type,u,w);
	else if(x>mid) addh(p*2+1,x,y,type,u,w);
	else addh(p*2,x,mid,type,u,w), addh(p*2+1,mid+1,y,type,u,w);
}

int d[N];
namespace SP{
	bool vst[N];
	struct Node {
		int u,w;
		bool operator < (const Node &a) const {
			return w>a.w;
		}
	};
	void dijkstra() {
		memset(d,0x3f,sizeof(d)); d[s]=0;
		priority_queue<Node>q; q.push((Node){s,0ll});
		while(!q.empty()) {
			int u=q.top().u; q.pop();
			if(vst[u]) continue;
			vst[u]=1;
			for(int i=hd[u],v;i;i=e[i].nxt) {
				if(!vst[v=e[i].to]&&d[v]>d[u]+e[i].w) {
					d[v]=min(d[v],d[u]+e[i].w);
					q.push((Node){v,d[v]});
				}
			}
		}
	}
}

signed main() {
	scanf("%lld%lld%lld",&n,&q,&s);
	build(1,1,n);
	for(int i=1,op,v,u,w,l,r;i<=q;i++) {
		scanf("%lld",&op);
		if(op==1)
			scanf("%lld%lld%lld",&v,&u,&w), add(v+8*n,u+8*n,w);
		else if(op==2)
			scanf("%lld%lld%lld%lld",&v,&l,&r,&w),
			addh(1,l,r,0,v,w);
		else if(op==3)
			scanf("%lld%lld%lld%lld",&v,&l,&r,&w),
			addh(1,l,r,1,v,w);
	}
	s+=8*n;
	SP::dijkstra();
	for(int i=1;i<=n;i++)
		if(d[i+8*n]<2e18) printf("%lld ",d[i+8*n]);
		else printf("-1 ");
	return 0;
}