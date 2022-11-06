#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
const ll lim=(2000*1000*1000)+1;
const ll MAXP=sqrt(lim)+4;
bool sieve_array[MAXP+1];
vector<ll> gpv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) {
		sieve_array[i] = true;
	}
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if(sieve_array[i]) {
			gpv.PB(i);
		}
	}
}

bool isPrime(ll x) {
	for (auto &p:gpv) {
		if (p>=x) break;
		if (0==(x%p)) return false;
	}
	return true;
}
ll solve(ll n) {
	if (isPrime(n)) return 1;
	else if (0==(n%2)) return 2;
	else if (n-2>=2&&isPrime(n-2)) return 2;
	else return 3;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
	ll n; scanf("%lld",&n);
	ll ans=solve(n);
	printf("%lld\n",ans);
}