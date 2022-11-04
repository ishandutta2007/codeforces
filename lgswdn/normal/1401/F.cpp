#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=(1<<19);
int n,m,a[N];

namespace SegT {
	int tot=1,sum[N<<1],tag[N<<1][19],d[N<<1],ls[N<<1],rs[N<<1];
	void build(int p,int l,int r) {
		if(l==r) {sum[p]=a[l], d[p]=0; return;} int mid=(l+r)/2;
		build(ls[p]=++tot,l,mid), build(rs[p]=++tot,mid+1,r);
		sum[p]=sum[ls[p]]+sum[rs[p]], d[p]=d[ls[p]]+1;
	}
	void pushdown(int p) {
		if(tag[p][d[p]]) swap(ls[p],rs[p]); tag[p][d[p]]=0;
		rep(i,0,d[p]-1) tag[ls[p]][i]^=tag[p][i], tag[rs[p]][i]^=tag[p][i], tag[p][i]=0;
	}
	void replace(int p,int l,int r,int x,int y) {
		if(l==r) {sum[p]=y; return;} int mid=(l+r)/2; pushdown(p);
		if(x<=mid) replace(ls[p],l,mid,x,y); else replace(rs[p],mid+1,r,x,y);
		sum[p]=sum[ls[p]]+sum[rs[p]];
	}
	int qry(int p,int l,int r,int x,int y) {
		if(l==x&&r==y) return sum[p]; int mid=(l+r)/2;
		pushdown(p);
		if(y<=mid) return qry(ls[p],l,mid,x,y);
		else if(x>mid) return qry(rs[p],mid+1,r,x,y);
		else return qry(ls[p],l,mid,x,mid)+qry(rs[p],mid+1,r,mid+1,y);
	}
	void reverse(int k) {
		rep(i,0,k) tag[1][i]^=1;
	}
	void swop(int k) {
		tag[1][k+1]^=1;
	}
}

signed main() {
	n=(1<<read()), m=read();
	rep(i,1,n) a[i]=read();
	SegT::build(1,1,n);
	rep(i,1,m) {
		int opt=read(), x=read();
		if(opt==1) SegT::replace(1,1,n,x,read());
		else if(opt==2) SegT::reverse(x);
		else if(opt==3) SegT::swop(x);
		else printf("%lld\n",SegT::qry(1,1,n,x,read()));
	}
	return 0;
}