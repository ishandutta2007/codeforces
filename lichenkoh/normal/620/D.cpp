#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define MAXN 2004
#define MAXN2 (MAXN*MAXN)
ll a[MAXN],b[MAXN];
pair<ll,pair<ll,ll> > c[MAXN2], d[MAXN2];

int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll m; cin >> m;
	for (ll i = 0; i < m; i++) {
		cin >> b[i];
	}
	ll sa = 0;
	ll sb = 0;
	for (ll i = 0; i < n; i++) {sa+=a[i];}
	for (ll i = 0; i < m; i++) {sb+=b[i];}
	// 0 case
	ll best = abs(sa-sb);
	ll anslen = 0;
	// 1 case
	ll besti = -1; ll bestj = -1;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ll cand = abs((sa+2*b[j]) - (sb+2*a[i]));
			if (cand < best) {
				best = cand;
				besti = i; bestj = j;
				anslen = 1;
			}
		}
	}
	// 2 case
	if (m>1) {
	ll esz = 0;
	for (ll i=0; i<n; i++) {
		for (ll j=i+1; j<n; j++) {
			ll v = 2*(a[i]+a[j]);
			c[esz] = MP(v, MP(i,j));
			esz++;
		}
	}
	sort(c,c+esz);
	ll fsz = 0;
	for (ll i=0; i<m; i++) {
		for (ll j=i+1; j<m; j++) {
			ll v = 2*(b[i]+b[j]);
			d[fsz] = MP(v, MP(i,j));
			fsz++;
		}
	}
	sort(d,d+fsz);
	ll cand[3];
	for (ll i = 0; i < esz; i++) {
		ll delta = sa-(sb + c[i].first);
		ll imin = 0; ll imax = fsz;
		while (imin<imax) {
			ll imid = (imin+imax)/2;
			if (delta + d[imid].first < 0) {
				imin = imid+1;
			}
			else {
				imax = imid;
			}
		}
		assert(imin==imax);
		cand[0] = max(imin-1,0LL);
		cand[1] = min(imin, fsz-1);
		cand[2] = fsz-1;
		for (ll k = 0; k < 3; k++) {
			ll candres = abs(delta+d[cand[k]].first);
			//printf("%I64d %I64d %I64d\n",i,cand[k],candres);
			if (candres < best) {
				best = candres;
				besti = i; bestj = cand[k];
				anslen = 2;
			}
		}
	}
	}
	printf("%I64d\n",best);
	printf("%I64d\n",anslen);
	if (anslen == 1) {
		assert(abs(sa+2*b[bestj]-(sb+2*a[besti])) == best);
		printf("%I64d %I64d\n",besti+1,bestj+1);
	}
	else if (anslen == 2) {
		pair<ll,ll> besta = c[besti].second;
		pair<ll,ll> bestb = d[bestj].second;
		assert(abs(sb+2*(a[besta.first]+a[besta.second])-(sa+2*(b[bestb.first]+b[bestb.second]))) == best);
		printf("%I64d %I64d\n",besta.first+1, bestb.first+1);
		printf("%I64d %I64d\n",besta.second+1, bestb.second+1);
	}

}