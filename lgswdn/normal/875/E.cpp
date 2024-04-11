#include<bits/stdc++.h>
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

const int N=1e5+9;

int n,s1,s2,x[N],mx;

namespace SegT {
	int tot=1,root=1,f[N*128],ls[N*128],rs[N*128];
	void clear() {
		rep(i,1,tot) f[i]=0, ls[i]=0, rs[i]=0; tot=1;
	}
	void mdf(int &p,int l,int r,int x,int z) {
		if(!p) p=++tot; if(l==r) {f[p]=z; return;} int mid=l+r>>1;
		if(x<=mid) mdf(ls[p],l,mid,x,z); else mdf(rs[p],mid+1,r,x,z);
		f[p]=f[ls[p]]|f[rs[p]];
	}
	void cl(int p,int l,int r,int x,int y) {
		if(x>y||(!p)||(!f[p])) return; if(l==r) {f[p]=0; return;} int mid=l+r>>1;
		if(y<=mid) cl(ls[p],l,mid,x,y); else if(x>mid) cl(rs[p],mid+1,r,x,y);
		else cl(ls[p],l,mid,x,mid), cl(rs[p],mid+1,r,mid+1,y);
		f[p]=f[ls[p]]|f[rs[p]];
	}
}
using SegT::root; using SegT::clear; using SegT::mdf; using SegT::cl; using SegT::f;

bool calc(int k) {
	clear();
	mdf(root,0,mx,s1,1); mdf(root,0,mx,s2,1);
	rep(i,0,n-1) {
		int l=-k+x[i+1], r=k+x[i+1]; l=max(l,0), r=min(r,mx);
		int rs=f[root];
		cl(root,0,mx,0,l-1), cl(root,0,mx,r+1,mx);
		if(i&&abs(x[i]-x[i+1])<=k&&rs) mdf(root,0,mx,x[i],1); 
	}
	return f[root];
}

signed main() {
	n=read(), s1=read(), s2=read(); mx=max(s1,s2);
	rep(i,1,n) x[i]=read(),mx=max(mx,x[i]);
	int l=abs(s1-s2),r=mx,ans=-1;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(calc(mid)) r=mid-1, ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}//