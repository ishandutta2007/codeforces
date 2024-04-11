#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct segment_tree{
	int l,r,cnt,v,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].v=min(t[ls(p)].v,t[rs(p)].v);
	t[p].cnt=(t[ls(p)].v==t[p].v?t[ls(p)].cnt:0)+(t[rs(p)].v==t[p].v?t[rs(p)].cnt:0);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void add_tag(int p,int v){
	t[p].v+=v;
	t[p].tag+=v;
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
void modify(int p,int l,int r){
	if(no_intersection)return;
	if(is_subset){
		t[p].cnt=1;
		return;
	}
	push_down(p);
	modify(ls(p),l,r);
	modify(rs(p),l,r);
	push_up(p);
}
int query(int p,int l,int r){
	if(no_intersection)return 0;
	if(is_subset)return t[p].cnt;
	push_down(p);
	return query(ls(p),l,r)+query(rs(p),l,r);
}
int a[maxn],n,st1[maxn],st2[maxn],tp1,tp2;
ll ans;
signed main(){
	scanf("%d",&n);
	for(ri i=1,x,y;i<=n;++i){
		scanf("%d%d",&x,&y);
		a[x]=y;
	}
	build(1,1,n);
	for(ri i=1;i<=n;++i){
		modify(1,1,i-1,-1);
		while(tp1&&a[i]>a[st1[tp1]]){
			modify(1,st1[tp1-1]+1,st1[tp1],a[i]-a[st1[tp1]]);
			--tp1;
		}
		st1[++tp1]=i;
		while(tp2&&a[i]<a[st2[tp2]]){
			modify(1,st2[tp2-1]+1,st2[tp2],-(a[i]-a[st2[tp2]]));
			--tp2;
		}
		st2[++tp2]=i;
		modify(1,i,i);
		ans+=t[1].cnt;
	}
	printf("%lld",ans);
	return 0;
}