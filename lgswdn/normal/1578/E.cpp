#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9;
typedef pair<int,int> pii;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,m,a[N];

int mx[N<<1],sum[N<<1],ls[N<<1],rs[N<<1],tot=1;
void build(int p,int l,int r) {
	if(l==r) {mx[p]=sum[p]=a[l]; return;} int mid=(l+r)/2;
	build(ls[p]=++tot,l,mid), build(rs[p]=++tot,mid+1,r);
	mx[p]=max(mx[ls[p]],mx[rs[p]]), sum[p]=sum[ls[p]]+sum[rs[p]];
}
void mmdf(int p,int l,int r,int x,int y,int k) {
	if(mx[p]<k) return;
	if(l==r) {mx[p]=sum[p]=(a[l]%=k); return;} int mid=(l+r)/2;
	if(y<=mid) mmdf(ls[p],l,mid,x,y,k);
	else if(x>mid) mmdf(rs[p],mid+1,r,x,y,k);
	else mmdf(ls[p],l,mid,x,mid,k), mmdf(rs[p],mid+1,r,mid+1,y,k);
	mx[p]=max(mx[ls[p]],mx[rs[p]]), sum[p]=sum[ls[p]]+sum[rs[p]];
}
void amdf(int p,int l,int r,int x,int k) {
	if(l==r) {mx[p]=sum[p]=(a[l]=k); return;} int mid=(l+r)/2;
	if(x<=mid) amdf(ls[p],l,mid,x,k); else amdf(rs[p],mid+1,r,x,k);
	mx[p]=max(mx[ls[p]],mx[rs[p]]), sum[p]=sum[ls[p]]+sum[rs[p]];
}
int qry(int p,int l,int r,int x,int y) {
	if(l==x&&r==y) return sum[p]; int mid=(l+r)/2;
	if(y<=mid) return qry(ls[p],l,mid,x,y);
	else if(x>mid) return qry(rs[p],mid+1,r,x,y);
	else return qry(ls[p],l,mid,x,mid)+qry(rs[p],mid+1,r,mid+1,y);
}

signed main() {
	n=read(), m=read();
	rep(i,1,n) a[i]=read();
	build(1,1,n);
	rep(i,1,m) {
		int opt=read(), x=read(), y=read();
		if(opt==1) printf("%lld\n",qry(1,1,n,x,y));
		else if(opt==2) mmdf(1,1,n,x,y,read());
		else if(opt==3) amdf(1,1,n,x,y);
		else throw "Trump";
	}
	return 0;
}