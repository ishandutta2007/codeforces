#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e6+10;
struct SGT{
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
	push_up(p);
}
void clear(int p){
	t[p].mn=t[p].tag=0;
	if(t[p].l==t[p].r)return;
	clear(ls(p)),clear(rs(p));
}
inline void push_down(int p){
	if(!t[p].tag)return;
	t[ls(p)].mn+=t[p].tag,t[rs(p)].mn+=t[p].tag;
	t[ls(p)].tag+=t[p].tag,t[rs(p)].tag+=t[p].tag;
	t[p].tag=0;
}
void modify(int p,int l,int r,int v){
	if(t[p].l>r||l>t[p].r)return;
	if(l<=t[p].l&&t[p].r<=r){
		t[p].mn+=v,t[p].tag+=v;
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
inline int query(int p,int l,int r){
	if(t[p].l>r||l>t[p].r)return INT_MAX;
	if(l<=t[p].l&&t[p].r<=r)return t[p].mn;
	push_down(p);
	return min(query(ls(p),l,r),query(rs(p),l,r));
}
int a[maxn],b[maxn],cnt,d[maxn],id[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		cnt=0;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),id[i]=i,d[++cnt]=a[i];
		sort(d+1,d+cnt+1);
		sort(id+1,id+n+1,[&](const int &x,const int &y){return a[x]<a[y];});
		for(ri i=1;i<=n;++i)a[i]=lower_bound(d+1,d+cnt+1,a[i])-d;
		for(ri i=1;i<=m;++i)scanf("%d",b+i);
		sort(b+1,b+m+1);
		build(1,1,n+1);
		ll ans=0;
		for(ri i=1;i<=n;++i){
			ans+=query(1,a[i],a[i]);
			modify(1,1,a[i]-1,1);
		}
		clear(1);
		for(ri i=1;i<=n;++i)modify(1,i+1,n+1,1);
		for(ri i=1,j=1,k=1;i<=m;++i){
			while(j<=n&&b[i]>=d[j])modify(1,id[j++]+1,n+1,-1);
			while(k<=n&&b[i]>d[k])modify(1,1,id[k++],1);
			ans+=t[1].mn;
		}
		printf("%lld\n",ans);
	}
	return 0;
}