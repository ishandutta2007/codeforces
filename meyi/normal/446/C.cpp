#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define ls(k) (k<<1)
#define rs(k) (k<<1|1)
typedef long long ll;
const int maxn=3e5+10,mod=1e9+9;
int a[maxn],m,n;
ll f[maxn];
inline ll getsum(ll x,ll y,int z){
	if(z==3)return x;
	if(z==4)return (x+y)%mod;
	return ((f[z-2]*x%mod)+(f[z-1]*y%mod)-y+mod)%mod;
}
struct segment_tree{
	int l,r;
	ll tag1,tag2,v;
}t[maxn<<2];
inline void push_up(int k){
	t[k].v=(t[ls(k)].v+t[rs(k)].v)%mod;
}
inline void push_down(int k){
	int tmp=ls(k),siz=t[tmp].r-t[tmp].l+1;
	if(siz)t[tmp].tag1=(t[tmp].tag1+t[k].tag1)%mod;
	if(siz>1)t[tmp].tag2=(t[tmp].tag2+t[k].tag2)%mod;
	t[tmp].v=(t[tmp].v+getsum(t[k].tag1,t[k].tag2,siz+2))%mod;
	ll x=t[k].tag1,y=t[k].tag2;
	if(siz)t[k].tag1=((f[siz-1]*x%mod)+(f[siz]*y%mod))%mod,t[k].tag2=((f[siz]*x%mod)+(f[siz+1]*y%mod))%mod;
	tmp=rs(k),siz=t[tmp].r-t[tmp].l+1;
	if(siz)t[tmp].tag1=(t[tmp].tag1+t[k].tag1)%mod;
	if(siz>1)t[tmp].tag2=(t[tmp].tag2+t[k].tag2)%mod;
	t[tmp].v=(t[tmp].v+getsum(t[k].tag1,t[k].tag2,siz+2))%mod;
	t[k].tag1=t[k].tag2=0;
}
void build(int k,int l,int r){
	t[k].l=l,t[k].r=r;
	if(l==r){
		t[k].v=a[l];
		return;
	}
	int mid=l+r>>1;
	build(ls(k),l,mid);
	build(rs(k),mid+1,r);
	push_up(k);
}
void add(int k,int l,int r){
	if(r<t[k].l||l>t[k].r)return;
	if(l<=t[k].l&&t[k].r<=r){
		int siz=t[k].r-t[k].l+1,v=t[k].l-l+1;
		if(siz)t[k].tag1=(t[k].tag1+f[v])%mod;
		if(siz>1)t[k].tag2=(t[k].tag2+f[v+1])%mod;
		t[k].v=(t[k].v+getsum(f[v],f[v+1],siz+2))%mod;
		return;
	}
	if(t[k].tag1||t[k].tag2)push_down(k);
	add(ls(k),l,r);
	add(rs(k),l,r);
	push_up(k);
}
ll query(int k,int l,int r){
	if(r<t[k].l||l>t[k].r)return 0;
	if(l<=t[k].l&&t[k].r<=r)return t[k].v;
	if(t[k].tag1||t[k].tag2)push_down(k);
	return (query(ls(k),l,r)+query(rs(k),l,r))%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	f[1]=1;
	for(ri i=2;i<=n+2;++i)f[i]=(f[i-1]+f[i-2])%mod;
	build(1,1,n);
	while(m--){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op&1)add(1,x,y);
		else printf("%lld\n",query(1,x,y));
	}
	return 0;
}