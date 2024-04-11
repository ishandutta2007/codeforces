#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll MAXP = 31625;
//const ll MAXP = 100;
const ll INF = 4611686018427387903LL;
bool tt[MAXP+8];
vector<ll> pv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) tt[i] = true;
	tt[0] = false; tt[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(tt[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				tt[j] = false;
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if (tt[i]) pv.PB(i);
	}
}

const ll MAXN = 1000008;

ll f[MAXN][3];
ll d[MAXN];
ll solve(ll *d, ll prime, ll initcost, ll n, ll a, ll b) {
	for (ll x=0;x<n;x++) {
		for (ll i=0;i<3;i++) {
			f[x][i] = INF;
		}
	}
	f[0][0] = initcost;
	for (ll x=1; x < n; x++) {
		f[x-1][1] = min(f[x-1][1], f[x-1][0]);
		f[x-1][2] = min(f[x-1][2], f[x-1][1]);
		if (d[x] % prime == 0) {
			f[x][0] = f[x-1][0];
			f[x][2] = f[x-1][2];
			f[x][1] = f[x-1][1]+a;
		}
		else if (((d[x]-1) % prime == 0) || ((d[x]+1) % prime == 0)) {
			f[x][0] = f[x-1][0] + b;
			f[x][1] = f[x-1][1] + a;
			f[x][2] = f[x-1][2] + b;
		}
		else {
			f[x][1] = f[x-1][1] + a;
		}
	}
	ll ans = INF;
	for (ll i=0;i<3;i++) {
		ans = min(ans, f[n-1][i]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	sieve();
	ll n,a,b; scanf("%I64d %I64d %I64d",&n,&a,&b);
	for (ll x=0;x<n;x++) {
		scanf("%I64d", &d[x]);
	}
	ll ans = INF;
	for (ll t = d[0]-1; t <= d[0]+1; t++) {
		set<ll> fac;
		ll y = t;
		for (auto &pr: pv) {
			if (y%pr == 0) {
				fac.insert(pr);
				y /= pr;
			}
		}
		fac.insert(y);
		for (auto &prime: fac) {
			if (prime == 1) continue;
			ll initcost = abs(t-d[0])*b;
			ll cand = solve(d, prime, initcost, n, a, b);
			ans = min(ans,cand);
		}
	}
	reverse(d,d+n);
	for (ll t = d[0]-1; t <= d[0]+1; t++) {
		set<ll> fac;
		ll y = t;
		for (auto &pr: pv) {
			if (y%pr == 0) {
				fac.insert(pr);
				y /= pr;
			}
		}
		fac.insert(y);
		for (auto &prime: fac) {
			if (prime == 1) continue;
			ll initcost = abs(t-d[0])*b;
			ll cand = solve(d, prime, initcost, n, a, b);
			ans = min(ans,cand);
		}
	}

	printf("%I64d\n",ans);
}