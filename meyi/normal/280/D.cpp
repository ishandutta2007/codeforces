#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct node{
	int l,r;
	ll sum;
	inline node operator+(const node &k){
		return {min(l,k.l),max(r,k.r),sum+k.sum};
	}
	inline bool operator<(const node &k)const{
		return sum<k.sum;
	}
	inline node operator-(){
		return {l,r,-sum};
	}
};
struct segment_tree{
	int l,r;
	node sum;
	node mx,mn;
	node lmx,rmx;
	node lmn,rmn;
	bool tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].sum=t[ls(p)].sum+t[rs(p)].sum;
	t[p].mx=max({t[ls(p)].mx,t[rs(p)].mx,t[ls(p)].rmx+t[rs(p)].lmx});
	t[p].mn=min({t[ls(p)].mn,t[rs(p)].mn,t[ls(p)].rmn+t[rs(p)].lmn});
	t[p].lmx=max(t[ls(p)].lmx,t[ls(p)].sum+t[rs(p)].lmx);
	t[p].lmn=min(t[ls(p)].lmn,t[ls(p)].sum+t[rs(p)].lmn);
	t[p].rmx=max(t[rs(p)].rmx,t[rs(p)].sum+t[ls(p)].rmx);
	t[p].rmn=min(t[rs(p)].rmn,t[rs(p)].sum+t[ls(p)].rmn);
}
int a[maxn];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].sum=t[p].mx=t[p].mn=t[p].lmx=t[p].rmx=t[p].lmn=t[p].rmn={l,l,a[l]};
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void add_tag(int p){
	t[p].sum=-t[p].sum;
	t[p].mx=-t[p].mx,t[p].mn=-t[p].mn;
	swap(t[p].mx,t[p].mn);
	t[p].lmx=-t[p].lmx,t[p].lmn=-t[p].lmn;
	swap(t[p].lmx,t[p].lmn);
	t[p].rmx=-t[p].rmx,t[p].rmn=-t[p].rmn;
	swap(t[p].rmx,t[p].rmn);
	t[p].tag^=1;
}
inline void push_down(int p){
	if(!t[p].tag)return;
	add_tag(ls(p));
	add_tag(rs(p));
	t[p].tag=0;
}
void modify1(int p,int k,int v){
	if(t[p].l>k||k>t[p].r)return;
	if(t[p].l==k&&k==t[p].r){
		t[p].sum=t[p].mx=t[p].mn=t[p].lmx=t[p].rmx=t[p].lmn=t[p].rmn={k,k,v};
		return;
	}
	push_down(p);
	modify1(ls(p),k,v);
	modify1(rs(p),k,v);
	push_up(p);
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
void modify2(int p,int l,int r){
	if(no_intersection)return;
	if(is_subset){
		add_tag(p);
		return;
	}
	push_down(p);
	modify2(ls(p),l,r);
	modify2(rs(p),l,r);
	push_up(p);
}
struct pdata{
	node sum,lmx,mx,rmx;
	inline pdata operator+(const pdata &k){
		if(!mx.l)return k;
		if(!k.mx.l)return *this;
		assert(rmx.r+1==k.lmx.l);
		return {sum+k.sum,max(lmx,sum+k.lmx),max({mx,k.mx,rmx+k.lmx}),max(k.rmx,rmx+k.sum)};
	}
}no_find;
pdata query(int p,int l,int r){
	if(no_intersection)return no_find;
	if(is_subset)return {t[p].sum,t[p].lmx,t[p].mx,t[p].rmx};
	push_down(p);
	return query(ls(p),l,r)+query(rs(p),l,r);
}
int m,n;
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	build(1,1,n);
	scanf("%d",&m);
	while(m--){
		ri op,x,y,z;
		scanf("%d%d%d",&op,&x,&y);
		if(op){
			scanf("%d",&z);
			ll ans=0;
			typedef pair<int,int> pii;
			#define fi first
			#define se second
			vector<pii>v;
			while(z--){
				node tmp=query(1,x,y).mx;
				if(tmp.sum<=0)break;
				ans+=tmp.sum;
				v.emplace_back(tmp.l,tmp.r);
				modify2(1,tmp.l,tmp.r);
			}
			printf("%lld\n",ans);
			for(auto i:v)modify2(1,i.fi,i.se);
		}
		else modify1(1,x,y);
	}
	return 0;
}