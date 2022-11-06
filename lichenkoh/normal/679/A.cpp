#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll UNDEF = -1LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXN=104;
bool a[MAXN+1];
vector<ll> pv;
void sieve() {
	for (ll i = 0; i <= MAXN; i++) a[i] = true;
	a[0] = false; a[1] = false;
	ll lim = sqrt(MAXN)+1;
	for (ll i = 2; i <= lim; i++) {
		if(a[i]) {
			for (ll j = i*i; j <= MAXN; j+=i) {
				a[j] = false;
			}
		}
	}
	for (ll i = 2; i <= MAXN; i++) {
		if (a[i]) pv.PB(i);
	}
}

int main() {
	sieve();
	ll primes=0;
	ll idx=0;
	ll q=0;
	while(1) {
		if (pv[idx]>100) break;
		if (q>=20) break;
		cout<<pv[idx]<<endl;
		q++;
		string s; cin>>s;
		if (s=="yes") {
			primes++;
			if (primes>=2) {
				cout<<"composite"<<endl;
				return 0;
			}
			if (q>=20) break;
			if (pv[idx]*pv[idx]<=100) {
				cout<<pv[idx]*pv[idx]<<endl;
				string t; cin>>t;
				if (t=="yes") {
					cout<<"composite"<<endl;
					return 0;
				}
				q++;
			}
		}
		idx++;
	}
	cout<<"prime"<<endl;
}