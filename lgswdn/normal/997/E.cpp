#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=2e5+9;
int n,m,a[N],l[N],r[N],ans[N],p[N];
vi id[N];

namespace SegT {
	int ls[N<<1],rs[N<<1],tot=1,s[N<<1],t[N<<1],ns[N<<1],tgs[N<<1],tgt[N<<1];
	void build(int p,int l,int r) {
		s[p]=-n-1;
		if(l==r) return; int mid=l+r>>1;
		build(ls[p]=++tot,l,mid), build(rs[p]=++tot,mid+1,r);
	}
	void pushs(int p) {
		s[ls[p]]+=tgs[p], s[rs[p]]+=tgs[p];
		tgs[ls[p]]+=tgs[p], tgs[rs[p]]+=tgs[p];
		tgs[p]=0;
	}
	void pusht(int p) {
		if(s[ls[p]]>=s[rs[p]]) tgt[ls[p]]+=tgt[p], t[ls[p]]+=ns[ls[p]]*tgt[p];
		if(s[rs[p]]>=s[ls[p]]) tgt[rs[p]]+=tgt[p], t[rs[p]]+=ns[rs[p]]*tgt[p];
		tgt[p]=0;
	}
	void pushdown(int p) {
		pusht(p), pushs(p);
	}
	void pushups(int p) {
		if(s[ls[p]]>s[rs[p]]) s[p]=s[ls[p]], ns[p]=ns[ls[p]];
		else if(s[ls[p]]<s[rs[p]]) s[p]=s[rs[p]], ns[p]=ns[rs[p]];
		else s[p]=s[ls[p]], ns[p]=ns[ls[p]]+ns[rs[p]];
	}
	void upds(int p,int l,int r,int x,int y,int k) {
		if(x>y) return;
		if(ls[p]) pushdown(p); int mid=l+r>>1;
		if(l==x&&r==y) {s[p]+=k, tgs[p]+=k; return;}
		if(y<=mid) upds(ls[p],l,mid,x,y,k);
		else if(x>mid) upds(rs[p],mid+1,r,x,y,k);
		else upds(ls[p],l,mid,x,mid,k), upds(rs[p],mid+1,r,mid+1,y,k);
		pushups(p);
		//cout<<"UPDWS "<<l<<" "<<r<<' '<<s[p]<<" "<<ns[p]<<endl;
	}
	void upds(int p,int l,int r,int x,int k) {
		if(ls[p]) pushdown(p); int mid=l+r>>1;
		if(l==x&&r==x) {s[p]=k, ns[p]=1; return;}
		if(x<=mid) upds(ls[p],l,mid,x,k);
		else upds(rs[p],mid+1,r,x,k);
		pushups(p);
		//cout<<"UPDS "<<l<<" "<<r<<' '<<s[p]<<" "<<ns[p]<<endl;
	}
	void updt(int p,int l,int r,int x,int y) {
		if(x>y) return;
		if(ls[p]) pushdown(p); int mid=l+r>>1;
		if(l==x&&r==y) {if(s[p]==-1) t[p]+=ns[p], tgt[p]++; return;}
		if(y<=mid) updt(ls[p],l,mid,x,y);
		else if(x>mid) updt(rs[p],mid+1,r,x,y);
		else updt(ls[p],l,mid,x,mid), updt(rs[p],mid+1,r,mid+1,y);
		t[p]=t[ls[p]]+t[rs[p]];
		//cout<<"UPDT "<<l<<" "<<r<<' '<<t[p]<<endl;
	}
	int qry(int p,int l,int r,int x,int y) {
		if(ls[p]) pushdown(p); int mid=l+r>>1;
		if(l==x&&r==y) return t[p];
		if(y<=mid) return qry(ls[p],l,mid,x,y);
		else if(x>mid) return qry(rs[p],mid+1,r,x,y);
		else return qry(ls[p],l,mid,x,mid)+qry(rs[p],mid+1,r,mid+1,y);
	}
}

signed main() {
	n=read(); rep(i,1,n) a[i]=read(), p[a[i]]=i; p[0]=p[n+1]=n+1;
	m=read(); rep(i,1,m) l[i]=read(), r[i]=read(), id[r[i]].emplace_back(i);
	SegT::build(1,1,n);
	rep(r,1,n) {
		int x=p[a[r]-1], y=p[a[r]+1]; if(x>y) swap(x,y);
		//cout<<r<<" "<<x<<" "<<y<<endl;
		SegT::upds(1,1,n,r,-1);
		if(x<r&&r<y) SegT::upds(1,1,n,x+1,r-1,-1);
		else if(y<r) SegT::upds(1,1,n,y+1,r-1,-1), SegT::upds(1,1,n,1,x,1);
		else if(r<x) SegT::upds(1,1,n,1,r-1,-1);
		SegT::updt(1,1,n,1,r);
		for(auto i:id[r]) ans[i]=SegT::qry(1,1,n,l[i],r);
	}
	rep(i,1,m) printf("%lld\n",ans[i]);
	return 0;
}