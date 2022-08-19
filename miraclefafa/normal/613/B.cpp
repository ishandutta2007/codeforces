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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
int n,val[N];
PII p[N];
ll A,cf,cm,m,s[N];
int main() {
	scanf("%d%lld%lld%lld%lld",&n,&A,&cf,&cm,&m);
	rep(i,1,n+1) {
		scanf("%d",&p[i].fi);
		p[i].se=i;
	}
	sort(p+1,p+n+1); p[n+1].fi=A;
	rep(i,1,n+1) s[i]=s[i-1]+p[i].fi;
	ll ans=0; int ansp=0,ansl=0,ansv=0;
	if (n*A-s[n]<=m) {
		ans=A*cm+n*cf;
		ansp=0; ansl=0; ansv=0;
	}
	rep(i,1,n+1) { // i+1..n ->A 
		ll c=(n-i)*A-(s[n]-s[i]);
		if (c>m) continue;
		ll rm=m-c;
		int l=1,r=i+1;
		while (l+1<r) {
			int md=(l+r)>>1;
			ll sm=(ll)p[md].fi*md-s[md];
			if (sm<=rm) l=md; else r=md;
		}
		rm-=((ll)p[l].fi*l-s[l]);
		ll nv=p[l+1].fi; if (l==i) nv=A;
		ll mm=min(p[l].fi+rm/l,nv);
		ll ret=mm*cm+(n-i)*cf;
		if (ret>=ans) {
			ans=ret; ansp=i; ansl=l; ansv=mm;
		}
	}
	printf("%lld\n",ans);
	rep(i,ansp+1,n+1) p[i].fi=A;
	rep(i,1,ansl+1) p[i].fi=ansv;
	rep(i,1,n+1) val[p[i].se]=p[i].fi;
	rep(i,1,n+1) printf("%d ",val[i]);
	puts("");
}