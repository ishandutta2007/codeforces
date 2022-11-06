#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll a[1008],b[1008];
const ll MAXN=2*1000*1000+1000;
bool prime[MAXN+1];
void sieve() {
	for (ll i = 0; i <= MAXN; i++) prime[i] = true;
	prime[0] = false; prime[1] = false;
	ll lim = sqrt(MAXN)+1;
	for (ll i = 2; i <= lim; i++) {
		if(prime[i]) {
			for (ll j = i*i; j <= MAXN; j+=i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	sieve();
	ll n; cin>>n;
	for (ll i=0;i<n;i++) {
		cin>>b[i];
	}
	ll m=0;
	ll ones=0;
	for (ll i=0;i<n;i++) {
		if (b[i]!=1) {
			a[m]=b[i];
			m++;
		}
		else ones++;
	}
	n=m;
	ll best=0;
	vector<ll> v;
	for (ll x=0;x<n;x++) {
		for (ll y=x+1;y<n;y++) {
			if (prime[a[x]+a[y]]) {
				if (prime[a[x]+1]&&prime[a[y]+1]) {
					ll cand=2+ones;
					if (cand>best) {
						v.clear();
						v.PB(a[x]); v.PB(a[y]);
						best=cand;
					}
				}
				else {
					ll cand=2;
					if (cand>best) {
						v.clear();
						v.PB(a[x]); v.PB(a[y]);
						best=cand;
					}
				}
			}
		}
	}
	for (ll x=0;x<n;x++) {
		if (prime[a[x]+1]) {
			ll cand=1+ones;
			if (cand>best) {
				v.clear();
				v.PB(a[x]);
				best=cand;
			}
		}
		else {
			ll cand=1;
			if (cand>best) {
				v.clear();
				v.PB(a[x]);
				best=cand;
			}
		}
	}
	{
		ll cand=ones;
		if (cand>best) {
			v.clear();
			best=cand;
		}
	}
	cout<<best<<endl;
	for (auto &w:v) {
		cout<<w<<" ";
	}
	for (ll i=0;i<best-v.size();i++) {
		cout<<1<<" ";
	}
	cout<<endl;
}