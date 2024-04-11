#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll read();
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=1e6+5;
int n;
struct Point {
	int x,y; ll a;
} p[N];
ll dp[N],ans;
struct Line {
	ll k,b;
	Line() {k=1,b=1;}
	Line(ll k,ll b):k(k),b(b) {}
	ll operator () (ll x) {return k*x+b;}
} seg[N<<2];
ll yy[N];
void change(int k,int l,int r,Line val) {
	int mid=l+r>>1;
	if(seg[k].k==1) return seg[k]=val,void();
	if(val(yy[mid])>seg[k](yy[mid])) swap(val,seg[k]);
	if(l==r) return;
	if(val.k<=seg[k].k) change(k<<1,l,mid,val);
	else change(k<<1|1,mid+1,r,val);
}
ll query(int k,int l,int r,int pos) {
	if(seg[k].k==1) return 0;
	if(l==r) return seg[k](yy[pos]);
	int mid=l+r>>1;
	if(pos<=mid) return max(seg[k](yy[pos]),query(k<<1,l,mid,pos));
	else return max(seg[k](yy[pos]),query(k<<1|1,mid+1,r,pos));
}
int main() {
	n=read();
	fr(i,1,n) {
		p[i].x=read();
		p[i].y=read();
		p[i].a=read();
		yy[i]=p[i].y;
	}
	sort(yy+1,yy+n+1);
	sort(p+1,p+n+1,[](const Point &a,const Point &b) {
		return a.x<b.x;
	});
	change(1,1,n,Line{0,0});
	fr(i,1,n) {
		dp[i]=query(1,1,n,lower_bound(yy+1,yy+n+1,p[i].y)-yy)+1ll*p[i].x*p[i].y-p[i].a;
		change(1,1,n,Line{-p[i].x,dp[i]});
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
ll read() {
	static ll x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}