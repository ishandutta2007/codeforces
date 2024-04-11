#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 
const ll MAXN=2e5+4;
const ll MAXP=MAXN;
bool sieve_array[MAXP+1];
ll sp[MAXP+1];
vector<ll> gpv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) {
		sieve_array[i] = true;
		sp[i]=INF;
	}
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
				chkmin(sp[j],i);
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if(sieve_array[i]) {
			gpv.PB(i);
			chkmin(sp[i],i);
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
	ll n; scanf("%lld",&n);
	ll hasp=0,hasc=0;
	for (ll x=2;x<=n+1;x++) {
		if (sieve_array[x]) hasp=1;
		if (!sieve_array[x]) hasc=1;
	}
	ll k=hasp+hasc;
	printf("%lld\n",k);
	for (ll x=2;x<=n+1;x++) {
		ll ans=0;
		if (sieve_array[x]) ans=hasp;
		if (!sieve_array[x]) ans=hasp+hasc;
		printf("%lld ",ans);
	}
	printf("\n");
}