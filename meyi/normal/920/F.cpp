#include<bits/stdc++.h>
using namespace std;
#define ri register int
const int maxa=1e6+10,maxn=3e5+10;
typedef long long ll;
struct segment_tree{
	int l,r,mx;
	ll sum;
}t[maxn<<2];
int a[maxn],cnt,d[maxa],pri[maxa],m,mx,n;
bool vis[maxa];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].sum=t[ls(p)].sum+t[rs(p)].sum;
	t[p].mx=max(t[ls(p)].mx,t[rs(p)].mx);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].sum=t[p].mx=a[l];
		return;
	}
	int mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline int query_mx(int p,int l,int r){
	if(t[p].l>r||l>t[p].r)return 0;
	if(l<=t[p].l&&t[p].r<=r)return t[p].mx;
	return max(query_mx(ls(p),l,r),query_mx(rs(p),l,r));
}
void modify(int p,int l,int r){
	if(t[p].l>r||l>t[p].r)return;
	if(t[p].l==t[p].r){
		t[p].sum=t[p].mx=d[t[p].mx];
		return;
	}
	if(query_mx(ls(p),l,r)>2)modify(ls(p),l,r);
	if(query_mx(rs(p),l,r)>2)modify(rs(p),l,r);
	push_up(p);
}
ll query_sum(int p,int l,int r){
	if(t[p].l>r||l>t[p].r)return 0;
	if(l<=t[p].l&&t[p].r<=r)return t[p].sum;
	return query_sum(ls(p),l,r)+query_sum(rs(p),l,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i),mx=max(a[i],mx);
	for(ri i=1;i<=mx;++i){
		++d[i];
		for(ri j=i<<1;j<=mx;j+=i)++d[j];
	}
	build(1,1,n);
	while(m--){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op&1)modify(1,l,r);
		else printf("%lld\n",query_sum(1,l,r));
	}
	return 0;
}