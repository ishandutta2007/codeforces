#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

ll inv(ll q,ll m) {
	q%=m;
	if (q==0) return 0; 
	ll a1=m,b1=0,a2=q,b2=1,a3,b3,t;
	while (a2!=1) {	t=a1/a2,a3=a1-t*a2,b3=b1-t*b2%m;
		a1=a2,a2=a3,b1=b2,b2=b3;if (b2<0) b2+=m;}
	return b2;
}

const int N=201000;
ll T,s[N],tot,d,v,prd[N],ret[N];
map<int,vector<pair<ll,int> > > hs;
set<ll> ss;
int a[N],n;
// tot*x mod T=b-a
ll order(ll a,ll b,ll tot,ll T) {
	b-=a; b%=T; if (b<0) b+=T;
	tot/=d; T/=d; b/=d;
	return b*v%T;
}
int main() {
	scanf("%lld%d",&T,&n);
	rep(i,0,n) {
		scanf("%d",a+i);
	}
	rep(i,1,n) s[i]=s[i-1]+a[i]; s[n]=s[n-1]+a[0];
	tot=s[n];
	d=__gcd(tot,T);
	v=inv(tot/d,T/d);
	rep(i,0,n) {
		if (ss.count(s[i]%T)) continue;
		ss.insert(s[i]%T);
		prd[i]=s[i]%d;
		ll c=order(prd[i],s[i],tot,T);
		hs[prd[i]].pb(mp(order(prd[i],s[i],tot,T),i));
	}
	ll fc=T/d;
	for (auto p:hs) {
		vector<pair<ll,int> > q=p.se;
		sort(all(q)); q.pb(mp(q[0].fi+fc,q[0].se));
		rep(i,0,SZ(q)-1) ret[q[i].se]=q[i+1].fi-q[i].fi;
	}
	rep(i,0,n) printf("%lld ",ret[i]); puts("");
}