#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll MAXN=2*100*1000 + 4;
ll a[MAXN];
ll p[MAXN];
ll med = -1;
ll n;
ld f(ll k) {
	ll suffix = p[n-1]-p[n-1-k];
	ll Q = p[med]-p[med-k-1];
	ld sum = suffix+Q;
	return sum/(2*k+1);
}

int main() {
	scanf("%I64d",&n);
	for (ll i=0;i<n;i++) {
		scanf("%I64d",&a[i]);
	}
	sort(a,a+n);
	p[0]=a[0];
	for (ll i=1;i<n;i++) {
		p[i]=p[i-1]+a[i];
	}
	ld best = 0;
	pair<ll,ll> bestp = MP(0LL,0LL);
	for (ll x=0;x<n;x++) {
		med=x;
		ll klim = min(n-1-med, med);
		if (klim>=1) {
			ll imin=0; ll imax=klim+1;
			while(imin<imax) {
				ll imid=imin+(imax-imin)/2;
				if (imid<klim && (f(imid+1) - f(imid)>0)) {
					imin=imid+1;
				}
				else {
					imax=imid;
				}
			}
			ld cand = f(imin) - a[med];
			//printf("%I64d %I64d %f %f\n",med,imin,(double)f(imin),(double)cand);
			if (cand>best) {
				best=cand;
				bestp=MP(med,imin);
			}
		}
	}
	printf("%I64d\n",bestp.second*2+1);
	for (ll x=bestp.first-bestp.second; x<=bestp.first;x++) {
		printf("%I64d ",a[x]);
	}
	for (ll x=n-bestp.second; x<=n-1; x++) {
		printf("%I64d ",a[x]);
	}
	printf("\n");
}