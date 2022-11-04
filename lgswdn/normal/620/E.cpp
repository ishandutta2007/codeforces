#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const int N=4e5+9; 

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

struct edge {int to,nxt;} e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,a[N],m,dt[N],st[N],ed[N],tick;

void dfs(int u,int fa) {
	dt[st[u]=++tick]=u;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa) continue;
		dfs(v,u);
	}
	ed[u]=tick;
}

struct node {int l,r,tag; ll s;} t[N<<2];
void build(int p,int l,int r) {
	t[p].l=l, t[p].r=r;
	if(l==r) {t[p].s=(1ll<<a[dt[l]]); return;}
	build(p*2,l,(l+r)/2), build(p*2+1,(l+r)/2+1,r);
	t[p].s=t[p*2].s|t[p*2+1].s;
}
void pushdown(int p) {
	t[p*2].tag=t[p*2+1].tag=t[p].tag;
	t[p*2].s=t[p*2+1].s=(1ll<<t[p].tag);
	t[p].tag=0;
}
void modify(int p,int x,int y,int c) {
	int l=t[p].l, r=t[p].r, mid=(l+r)/2;
	if(l==x&&r==y) {t[p].s=(1ll<<c),t[p].tag=c; return;}
	if(t[p].tag) pushdown(p);
	if(y<=mid) modify(p*2,x,y,c);
	else if(x>mid) modify(p*2+1,x,y,c);
	else modify(p*2,x,mid,c), modify(p*2+1,mid+1,y,c);
	t[p].s=t[p*2].s|t[p*2+1].s;
}
ll query(int p,int x,int y) {
	int l=t[p].l, r=t[p].r, mid=(l+r)/2;
	if(l==x&&y==r) return t[p].s;
	if(t[p].tag) pushdown(p);
	if(y<=mid) return query(p*2,x,y);
	else if(x>mid) return query(p*2+1,x,y);
	else return query(p*2,x,mid)|query(p*2+1,mid+1,y);
}

int main() {
	n=read(), m=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n-1) {
		int u=read(), v=read();
		add(u,v), add(v,u);
	}
	dfs(1,0);
	build(1,1,n);
	rep(i,1,m) {
		int opt=read(), u=read();
		if(opt==1) modify(1,st[u],ed[u],read());
		else {
			ll s=query(1,st[u],ed[u]); int ans=0;
			rep(h,0,60) ans+=(bool)(s&(1ll<<h));
			printf("%d\n",ans);
		}
	}
	return 0;
}