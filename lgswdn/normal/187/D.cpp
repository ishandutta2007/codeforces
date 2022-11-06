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

const int N=2e5+9;
int n,g,r,pp,l[N],d[N],f[N];

namespace SegT {
	int ls[N<<5],rs[N<<5],v[N<<5],tot=1;
	void ins(int &p,int l,int r,int x,int y) {
		if(!p) p=++tot, v[p]=n+1; v[p]=min(v[p],y);
		if(l==r) return; int mid=(l+r)/2;
		if(x<=mid) ins(ls[p],l,mid,x,y); else ins(rs[p],mid+1,r,x,y);
	}
	int qry(int p,int l,int r,int x,int y) {
		if(!p) return n+1;
		if(l==x&&r==y) return v[p]; int mid=(l+r)/2;
		if(y<=mid) return qry(ls[p],l,mid,x,y);
		else if(x>mid) return qry(rs[p],mid+1,r,x,y);
		else return min(qry(ls[p],l,mid,x,mid),qry(rs[p],mid+1,r,mid+1,y));
	}
}

int nxt(int x) {
	if(x<=g) return SegT::qry(1,0,pp-1,g-x,pp-1-x);
    else return min(SegT::qry(1,0,pp-1,0,pp-1-x),SegT::qry(1,0,pp-1,pp-x+g,pp-1));
}

signed main() {
	n=read(), g=read(), r=read(), pp=g+r; int rr=1;
	rep(i,0,n) l[i]=read();
	rep(i,1,n+1) d[i]=d[i-1]+l[i-1];
	per(i,n,0) {
		int j=nxt((pp-d[i]%pp)%pp);
		if(j<=n) f[i]=(d[j]-d[i]+pp)/pp*pp+f[j];
		else f[i]=d[n+1]-d[i];
		if(i) SegT::ins(rr=1,0,pp-1,d[i]%pp,i);
	}
	int lst=0;
	int q=read();
	rep(i,1,q) {
		int x=read(), y=nxt(x%pp); lst=0;
		if(y<=n) lst=((x+d[y]+pp)/pp*pp)+f[y];
		else lst=x+d[n+1];
		printf("%lld\n",lst);
	}
	return 0;
}