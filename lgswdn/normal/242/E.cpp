#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a[N],m;

bool bit(int s,int i) {return s&(1ll<<i);}

struct segment_tree {
	struct node {int cnt,tag;} t[N<<2];
	void build(int p,int l,int r,int k) {
		if(l==r) {t[p].cnt=bit(a[l],k); return;}
		build(p*2,l,(l+r)/2,k), build(p*2+1,(l+r)/2+1,r,k);
		t[p].cnt=t[p*2].cnt+t[p*2+1].cnt;
	}
	void pushdown(int p,int l,int r) {
		if(t[p].tag) {
			t[p*2].tag^=1, t[p*2+1].tag^=1;
			t[p*2].cnt=(l+r)/2-l+1-t[p*2].cnt;
			t[p*2+1].cnt=r-(l+r)/2-t[p*2+1].cnt;
			t[p].tag=0;
		}
	}
	void modify(int p,int x,int y,int l,int r) {
		int mid=(l+r)/2;
		if(x==l&&y==r) {t[p].cnt=r-l+1-t[p].cnt, t[p].tag^=1; return;}
		pushdown(p,l,r);
		if(y<=mid) modify(p*2,x,y,l,mid);
		else if(x>mid) modify(p*2+1,x,y,mid+1,r);
		else modify(p*2,x,mid,l,mid), modify(p*2+1,mid+1,y,mid+1,r);
		t[p].cnt=t[p*2].cnt+t[p*2+1].cnt;
	}
	int query(int p,int x,int y,int l,int r) {
		int mid=(l+r)/2;
		if(x==l&&y==r) return t[p].cnt;
		pushdown(p,l,r);
		if(y<=mid) return query(p*2,x,y,l,mid);
		else if(x>mid) return query(p*2+1,x,y,mid+1,r);
		else return query(p*2,x,mid,l,mid)+query(p*2+1,mid+1,y,mid+1,r);
	}
}st[21];

signed main() {
	n=read();
	rep(i,1,n) a[i]=read();
	rep(h,0,19) st[h].build(1,1,n,h);
	m=read();
	rep(i,1,m) {
		int opt=read(), l=read(), r=read();
		if(opt==1) {
			int ans=0;
			rep(h,0,19) ans+=st[h].query(1,l,r,1,n)*(1ll<<h);
			printf("%lld\n",ans);
		} else {
			int x=read();
			rep(h,0,19) if(bit(x,h)) st[h].modify(1,l,r,1,n);
		}
	}
	return 0;
}