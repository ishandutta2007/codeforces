#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9,inf=0x3f3f3f3f3f3f3f3f;
typedef pair<int,int>pii;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,a[N],p[N],m,b[N],bd[N];

int tot=1,ls[N],rs[N],val[N],tag[N];
void build(int p,int l,int r) {
	val[p]=inf;
	if(l==r) return; int mid=(l+r)/2;
	build(ls[p]=++tot,l,mid), build(rs[p]=++tot,mid+1,r);
}
void pushdown(int p) {
	if(tag[p]) {
		if(val[ls[p]]!=inf) val[ls[p]]+=tag[p], tag[ls[p]]+=tag[p];
		if(val[rs[p]]!=inf) val[rs[p]]+=tag[p], tag[rs[p]]+=tag[p];
		tag[p]=0;
	}
}
void add(int k) {if(val[1]!=inf) val[1]+=k, tag[1]+=k;}
void add(int p,int l,int r,int x,int y,int k) {
	if(l==x&&r==y) {if(val[p]!=inf) val[p]+=k, tag[p]+=k; return;}
	int mid=(l+r)/2; pushdown(p);
	if(y<=mid) add(ls[p],l,mid,x,y,k);
	else if(x>mid) add(rs[p],mid+1,r,x,y,k);
	else add(ls[p],l,mid,x,mid,k), add(rs[p],mid+1,r,mid+1,y,k);
	val[p]=min(val[ls[p]],val[rs[p]]);
}
void mdf(int p,int l,int r,int x,int y) {
	if(l==r) {val[p]=min(val[p],y); return;}
	int mid=(l+r)/2; pushdown(p);
	if(x<=mid) mdf(ls[p],l,mid,x,y);
	else mdf(rs[p],mid+1,r,x,y);
	val[p]=min(val[ls[p]],val[rs[p]]);
}
int qry(int p,int l,int r,int x) {
	if(l==r) return val[p];
	int mid=(l+r)/2; pushdown(p);
	if(x<=mid) return qry(ls[p],l,mid,x);
	else return qry(rs[p],mid+1,r,x);
}

signed main() {
	n=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n) p[i]=read();
	m=read();
	rep(i,1,m) b[i]=read(), bd[b[i]]=i;
	build(1,0,m); mdf(1,0,n,0,0);
	rep(i,0,n-1) {
		int pos=bd[a[i+1]]-1,ff=0;
		if(pos>=0) ff=qry(1,0,m,pos);
		if(p[i+1]<=0) add(p[i+1]);
		else {
			int pq=lower_bound(b+1,b+m+1,a[i+1])-b-1;
			add(1,0,m,0,pq,p[i+1]);
			//cout<<"ADD "<<0<<" "<<pq<<" "<<p[i+1]<<endl;
		}
		if(pos>=0) mdf(1,0,m,pos+1,ff);
	}
	if(qry(1,0,m,m)==inf) puts("NO");
	else printf("YES\n%lld\n",qry(1,0,m,m));
	return 0;
}