#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int inf=0x3f3f3f3f,maxn=5e5+10;
struct segment_tree{
	int l,r,mn,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].mn=min(t[ls(p)].mn,t[rs(p)].mn);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].mn=t[p].tag=0;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
inline void add_tag(int p,int v){
	t[p].mn+=v,t[p].tag+=v;
}
inline void push_down(int p){
	if(!t[p].tag)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=0;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
void modify(int p,int l,int r,int v){
	if(no_intersection)return;
	if(is_subset){
		add_tag(p,v);
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
void debug(int p){
	if(t[p].l==t[p].r){
		printf("%lld ",t[p].mn);
		if(p==1)putchar(10);
		return;
	}
	push_down(p);
	debug(ls(p));
	debug(rs(p));
	if(p==1)putchar(10);
}
int a[maxn],bl,id[maxn],m,n,t_case;
typedef pair<ll,int> pli;
#define fi first
#define se second
pli b[maxn];
vector<int>c[maxn],d[maxn];
ll sum[maxn];
bool vis[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		bl=0;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),b[++bl]={a[i],1};
		for(ri i=1,x;i<=m;++i){
			scanf("%d",&x);
			c[i].resize(x),d[i].resize(x);
			sum[i]=0;
			for(ri &j:c[i])scanf("%d",&j),sum[i]+=j;
			b[++bl]={sum[i],x};
			for(ri &j:c[i])b[++bl]={sum[i]-j,x-1};
		}
		auto cmp=[&](pli x,pli y){return x.fi*y.se!=y.fi*x.se?x.fi*y.se<y.fi*x.se:x.se>y.se;};
		sort(b+1,b+bl+1,cmp);
		bl=unique(b+1,b+bl+1)-b-1;
//		for(ri i=1;i<=bl;++i)printf("! %lld %d\n",b[i].fi,b[i].se);
		build(1,1,bl);
		for(ri i=1;i<=n;++i){
			ri tmp=lower_bound(b+1,b+bl+1,pli{a[i],1},cmp)-b;
//			printf("!! %d\n",tmp);
			modify(1,1,tmp,1);
		}
		for(ri i=1;i<=m;++i){
			id[i]=lower_bound(b+1,b+bl+1,pli{sum[i],c[i].size()},cmp)-b;
//			printf("!!! %d\n",id[i]);
			modify(1,1,id[i],-1);
			for(ri j=0;j<c[i].size();++j){
				d[i][j]=lower_bound(b+1,b+bl+1,pli{sum[i]-c[i][j],c[i].size()-1},cmp)-b;
				if(!vis[d[i][j]])modify(1,d[i][j],d[i][j],inf),vis[d[i][j]]=true;
			}
		}
		for(ri i=1;i<=m;++i){
			modify(1,1,id[i],1);
			modify(1,id[i],id[i],inf);
			for(ri j=0;j<c[i].size();++j){
//				printf("!!!! %d\n",d[i][j]);
				modify(1,1,d[i][j],-1);
				modify(1,d[i][j],d[i][j],-inf);
//				debug(1);
				putchar((t[1].mn>=0)|48);
				modify(1,1,d[i][j],1);
				modify(1,d[i][j],d[i][j],inf);
				vis[d[i][j]]=false;
			}
			modify(1,1,id[i],-1);
			modify(1,id[i],id[i],-inf);
		}
		putchar(10);
	}
	return 0;
}