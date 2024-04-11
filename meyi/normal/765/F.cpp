#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=3e5+10,maxn=1e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct segment_tree{
	int l,r,mn;
	vector<int>v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
int mn;
inline void push_up(int p){
	ckmin(t[p].mn,min(t[ls(p)].mn,t[rs(p)].mn));
	ckmin(mn,t[p].mn);
}
int a[maxn];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].mn=INT_MAX;
	for(ri i=l;i<=r;++i)t[p].v.push_back(a[i]);
	sort(t[p].v.begin(),t[p].v.end());
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
void modify(int p,int k,int v){
	if(t[p].l>k)return;
	if(t[p].r<=k){
		auto it=upper_bound(t[p].v.begin(),t[p].v.end(),v);
		if(it!=t[p].v.end())ckmin(t[p].mn,*it-v);
		if(it!=t[p].v.begin())ckmin(t[p].mn,v-*prev(it));
		if(t[p].mn>=mn)return;
	}
	if(t[p].l==t[p].r){
		ckmin(mn,t[p].mn);
		return;
	}
	modify(rs(p),k,v);
	modify(ls(p),k,v);
	push_up(p);
}
int query(int p,int l,int r){
	if(l>t[p].r||t[p].l>r)return INT_MAX;
	if(l<=t[p].l&&t[p].r<=r)return t[p].mn;
	return min(query(ls(p),l,r),query(rs(p),l,r));
}
int ans[maxm],m,n;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>q[maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	build(1,1,n);
	scanf("%d",&m);
	for(ri i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		q[y].emplace_back(x,i);
	}
	for(ri i=2;i<=n;++i){
		mn=INT_MAX;
		modify(1,i-1,a[i]);
		for(auto j:q[i])ans[j.se]=query(1,j.fi,i-1);
	}
	for(ri i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}