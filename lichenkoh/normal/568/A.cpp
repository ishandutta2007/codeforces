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

const ll MAXN=1e8;
const ll MAXP=MAXN;
bitset<MAXP+1> sieve_array;
void sieve() {
	sieve_array.set();
	sieve_array[0] = false; sieve_array[1] = false;
	int lim = sqrt(MAXP)+1;
	for (int i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (long long j = (long long)i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
			}
		}
	}
}
ll pten[]={1,10,100,1000,10000};
bitset<MAXN+1> vpalin;
void init() {
	vpalin.reset();
	for (ll x=1;x<=9;x++) vpalin[x]=true;
	for (ll x=1;x<10000;x++) {
		string s=to_string(x);
		reverse(s.begin(),s.end());
		ll r=stoi(s);
		ll len=s.length();
		ll ans=x*pten[len]+r;
		if (ans<MAXN) vpalin[ans]=true;
		if (x<1000) for (ll y=0;y<10;y++) {
			ans=x*pten[len+1]+y*pten[len]+r;
			if (ans<MAXN) vpalin[ans]=true;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
	init();
	long long p,q; scanf("%lld%lld",&p,&q);
	ll prime=0;
	ll palin=0;
	ll ans=-1;
	for (ll n=1;n<MAXN;n++) {
		if (sieve_array[n]) {
			prime++;
		}
		if (vpalin[n]) {
			//if (n==99999999) printf("%d\n",n);
			palin++;
		}
		if (((long long)prime)*q<=((long long)p)*palin) {
			//printf("n:%d prime:%d palin:%d\n",n,prime,palin);
			chkmax(ans,n);
		}
	}
	printf("%d\n",ans);
}