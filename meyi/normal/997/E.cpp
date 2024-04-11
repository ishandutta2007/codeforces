#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=12e4+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct SGT{
	int l,r,cnt,mn,tag1;
	ll his,tag2;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].mn=min(t[ls(p)].mn,t[rs(p)].mn);
	t[p].cnt=(t[ls(p)].mn==t[p].mn?t[ls(p)].cnt:0)+(t[rs(p)].mn==t[p].mn?t[rs(p)].cnt:0);
	t[p].his=t[ls(p)].his+t[rs(p)].his;
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
inline void add_tag(int p,int v1,ll v2){
	if(v1)t[p].mn+=v1,t[p].tag1+=v1;
	if(v2)t[p].his+=t[p].cnt*v2,t[p].tag2+=v2;
}
inline void push_down(int p){
	if(!t[p].tag1&&!t[p].tag2)return;
	add_tag(ls(p),t[p].tag1,0);
	add_tag(ls(p),0,t[ls(p)].mn==t[p].mn?t[p].tag2:0);
	add_tag(rs(p),t[p].tag1,0);
	add_tag(rs(p),0,t[rs(p)].mn==t[p].mn?t[p].tag2:0);
	t[p].tag1=t[p].tag2=0;
}
void modify(int p,int l,int r,int v){
	if(t[p].l>r||l>t[p].r)return;
	if(l<=t[p].l&&t[p].r<=r){
		add_tag(p,v,0);
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
void insert(int p,int k){
	if(t[p].l>k||k>t[p].r)return;
	if(t[p].l==t[p].r){
		t[p].cnt=1;
		return;
	}
	push_down(p);
	insert(ls(p),k);
	insert(rs(p),k);
	push_up(p);
}
ll query(int p,int l,int r){
	if(t[p].l>r||l>t[p].r)return 0;
	if(l<=t[p].l&&t[p].r<=r)return t[p].his;
	push_down(p);
	return query(ls(p),l,r)+query(rs(p),l,r);
}
int a[maxn],m,n,st1[maxn],st2[maxn],tp1,tp2;
ll ans[maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>q[maxn];
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	scanf("%d",&m);
	for(ri i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		q[y].emplace_back(x,i);
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
			modify(1,st2[tp2-1]+1,st2[tp2],a[st2[tp2]]-a[i]);
			--tp2;
		}
		st2[++tp2]=i;
		insert(1,i);
		add_tag(1,0,1);
		for(auto j:q[i])ans[j.se]=query(1,j.fi,i);
	}
	for(ri i=1;i<=m;++i)printf("%lld\n",ans[i]);
	return 0;
}