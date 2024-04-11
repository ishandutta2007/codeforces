#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head


const int N=201000;
int h[N],s[N],n,q,l,r;
ll d[N];
struct info {
	ll lm,rm,res;
	info() {}
	info(ll l,ll r,ll re):lm(l),rm(r),res(re) {}
}nd[4*N];
info operator + (const info &a, const info &b) {
	return info(max(a.lm,b.lm),max(a.rm,b.rm),max(max(a.res,b.res),a.lm+b.rm));
}
void build(int p,int l,int r) {
	if (l==r) nd[p]=info(2*h[l]-d[l],2*h[l]+d[l],-1ll<<60);
	else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		nd[p]=nd[p+p]+nd[p+p+1];
	}
}
info query(int p,int l,int r,int pl,int pr) {
	if (l==pl&&r==pr) return nd[p];
	else {
		int md=(l+r)>>1;
		if (pr<=md) return query(p+p,l,md,pl,pr);
		else if (pl>md) return query(p+p+1,md+1,r,pl,pr);
		else return query(p+p,l,md,pl,md)+query(p+p+1,md+1,r,md+1,pr);
	}
}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) scanf("%d",s+i);
	rep(i,1,n+1) scanf("%d",h+i);
	rep(i,1,n+1) d[i+1]=d[i]+s[i];
	rep(i,1,n+1) d[i+n+1]=d[i+n]+s[i],h[i+n]=h[i];
	build(1,1,2*n);
	rep(i,0,q) {
		scanf("%d%d",&l,&r);
		if (r<l) r+=n;
		info rt=query(1,1,2*n,r+1,l+n-1);
		printf("%I64d\n",rt.res);
	}
}