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
const ll MAXN=sqrt(1000)+2;
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
map<ll,ll> factorize(ll x) {
	map<ll,ll> h;
	while(x>=MAXP) {
		bool found=false;
		for (auto &p:gpv) {
			if (p*p>x) break;
			if ((x%p)==0) {
				x/=p;
				h[p]++;
				found=true;
				break;
			}
		}
		if (!found) break;
	}
	if (x<MAXP) {
		while(x>1) {
		ll p=sp[x];
		x/=p;
		h[p]++;
		}
	}
	if (x>1) h[x]++;
	return h;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
	ll n; cin>>n;
	map<ll,ll> h;
	for (ll x=1;x<=n;x++) {
		map<ll,ll> factor=factorize(x);
		for (auto &w:factor) {
			chkmax(h[w.first],w.second);
		}
	}
	vll ans;
	for (auto &w:h) {
		ll x=w.fst;
		for (ll i=1;i<=w.snd;i++) {
			ans.PB(x);
			x*=w.fst;
		}
	}
	printf("%lld\n",(ll)ans.size());
	for (auto &w:ans) printf("%lld ",w);
	printf("\n");
}