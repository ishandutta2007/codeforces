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

const int N=101000;
int n,S,ss,aa,bb;
pair<int,PII> p[N];
ll pres[N],prea[N],sufb[N],ret,tot;
int main() {
	scanf("%d%d",&n,&S);
	rep(i,1,n+1) {
		scanf("%d%d%d",&ss,&aa,&bb);
		p[i]=mp(ss,mp(aa,bb));
		tot+=ss;
	}
	ll r=(tot+S-1)/S;
	sort(p+1,p+n+1,[&](pair<int,PII> x,pair<int,PII> y){ return x.se.fi-x.se.se>y.se.fi-y.se.se; });
	rep(i,1,n+2) {
		pres[i]=pres[i-1]+p[i].fi;
		prea[i]=prea[i-1]+(ll)p[i].fi*p[i].se.fi;
	}
	per(i,0,n+1) {
		sufb[i]=sufb[i+1]+(ll)p[i].fi*p[i].se.se;
	}
//	rep(i,1,n+1) printf("%d %d %d\n",p[i].fi,p[i].se.fi,p[i].se.se);
	rep(i,1,n+1) {
		// 1~i pa
		ll pa=pres[i-1],pb=tot-p[i].fi-pa;
		ll cur=prea[i-1]+sufb[i+1];
		ll curr=(pa+S-1)/S+(pb+S-1)/S;
		if (curr>r) continue;
		ll rema=(S-pa%S)%S,remb=(S-pb%S)%S;
//		printf("%lld %lld %lld %lld %lld %lld\n",pa,pb,cur,curr,rema,remb);
		if (p[i].se.fi>p[i].se.se) {
			// prefer a
			rema+=(r-curr)*S;
			ll c=p[i].fi;
			if (rema+remb<c) continue;
			cur+=min(c,rema)*p[i].se.fi;
			c-=min(c,rema);
			cur+=c*p[i].se.se;
		} else {
			remb+=(r-curr)*S;
			ll c=p[i].fi;
			if (rema+remb<c) continue;
			cur+=min(c,remb)*p[i].se.se;
			c-=min(c,remb);
			cur+=c*p[i].se.fi;
		}
		ret=max(ret,cur);
	}
	printf("%lld\n",ret);
}