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
const ll INF=1<<30;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=1000000+4;
const ll MAXP=MAXN;
bool sieve_array[MAXP+1];
ll sp[MAXP+1];
vector<ll> pv;
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
			chkmin(sp[i],i);
		}
	}
}
int c[MAXN];
ll fk[MAXN];
int main() {
	sieve();
	int n,k; scanf("%d %d",&n,&k);
	for (ll i=0;i<n;i++) scanf("%d",&c[i]);
	// Factorize k
	for (ll i=0;i<MAXN;i++) fk[i]=0;
	while(k>1) {
		ll p=sp[k];
		//printf("k has factor: %d\n",p);
		fk[p]++;
		k/=p;
	}
	for (ll i=0;i<n;i++) {
		ll x=c[i];
		ll curp=INF;
		ll cnt=0;
		while(1) {
			ll p=sp[x];
			if (p!=curp) {
				if (curp!=INF) {
					//printf("%d has factor: %d with cnt: %d\n",c[i],curp,cnt);
					if (fk[curp]<=cnt) fk[curp]=0;
				}
				cnt=0;
				curp=p;
			}
			if (p==INF) break;
			cnt++;
			x/=p;
		}
	}
	for (ll i=0;i<MAXN;i++) {
		if (fk[i]!=0) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}