#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define mod 998244353
#define N 200009
using namespace std;

int n,m,tp,s[N<<2],sz[N<<2]; pii q[N];
set<pii > S[N]; set<pii > :: iterator it;
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
struct node{ int x,y; }icr[N<<2];
node mrg(node u,node v){
	return (node){(ll)u.x*v.x%mod,((ll)u.y*v.x+v.y)%mod};	
}
void mdy(int x,node y){
	//cerr<<"Sz:"<<sz[x]<<endl;
	s[x]=((ll)s[x]*y.x+(ll)y.y*sz[x])%mod; icr[x]=mrg(icr[x],y);
}
void pushdn(int k){
	mdy(k<<1,icr[k]); mdy(k<<1|1,icr[k]); icr[k]=(node){1,0};
}
void mdy(int k,int l,int r,int x,int y,node z){
//	if (l==1 && r==n) cerr<<":"<<x<<' '<<y<<' '<<z.x<<' '<<z.y<<endl;
	if (x<=l && r<=y){
		mdy(k,z); //cerr<<l<<' '<<r<<' '<<s[k]<<endl;
		return;
	}
	pushdn(k);
	int mid=l+r>>1;
	if (x<=mid) mdy(k<<1,l,mid,x,y,z); if (y>mid) mdy(k<<1|1,mid+1,r,x,y,z);
	s[k]=(s[k<<1]+s[k<<1|1])%mod;
	//cerr<<l<<' '<<r<<' '<<s[k]<<endl;
}
int qry(int k,int l,int r,int x,int y){
	if (x<=l && r<=y) return s[k];
	pushdn(k);
	int mid=l+r>>1,ans=0;
	if (x<=mid) ans+=qry(k<<1,l,mid,x,y);
	if (y>mid) ans+=qry(k<<1|1,mid+1,r,x,y);
	return ans%mod;
}
void build(int k,int l,int r){
	icr[k]=(node){1,0};
	if (l==r){ sz[k]=1; return; }
	int mid=l+r>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
	sz[k]=sz[k<<1]+sz[k<<1|1];	
}
bool check(pii p,int l,int r){
	return p.fi<=r && p.se>=l;	
}
int main(){
	n=read(); m=read();
	int i,x,l,r;
	for (i=1; i<=n; i++){
		S[i].insert(mpr(0,0));
		S[i].insert(mpr(n+1,n+1));
	}
	build(1,1,n);
	while (m--){
		i=read();
		if (i==1){
			l=read(); r=read(); x=read();
			it=S[x].lower_bound(mpr(l,r)); it--;
			if (!check(*it,l,r)) it++;
			for (; check(*it,l,r); it++) q[++tp]=*it;
			if (!tp){
				mdy(1,1,n,l,r,(node){1,1});
				S[x].insert(mpr(l,r)); continue;
			}
			for (i=1; i<tp; i++) if (q[i].se+1<q[i+1].fi)
				mdy(1,1,n,q[i].se+1,q[i+1].fi-1,(node){1,1});
			if (l<q[1].fi) mdy(1,1,n,l,q[1].fi-1,(node){1,1});
			if (q[tp].se<r) mdy(1,1,n,q[tp].se+1,r,(node){1,1});
			for (i=1; i<=tp; i++) mdy(1,1,n,max(q[i].fi,l),min(q[i].se,r),(node){2,0});
			q[0]=mpr(min(q[1].fi,l),max(q[tp].se,r));
			for (; tp; tp--) S[x].erase(q[tp]);
			S[x].insert(q[0]);
		} else{
			l=read(); r=read();
			printf("%d\n",qry(1,1,n,l,r));
		}
	}
	return 0;
}