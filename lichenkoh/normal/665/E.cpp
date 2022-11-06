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
const ll MAXN=(1000*1000)+10;
const ll POP=26;
ll a[MAXN];
ll g[1ULL<<POP];
int main() {
	ll n,k; scanf("%d %d",&n,&k);
	for (ll i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	k--;
	ll rawmask=0;
	long long final=0;
	for (ll t=30;t>=1;t--) {
		//printf("t:%d\n",t);
		rawmask|=1ULL<<t;
		if (k&(1ULL<<(t-1))) continue;
		else {
			ll need=rawmask&k;
			assert(0==(need&(1ULL<<(t-1))));
			need|=1ULL<<(t-1);
			ll mask=rawmask|(1ULL<<(t-1));
			ll popcnt=__builtin_popcountll(mask);
			if (popcnt<=POP) {
				ll lim=1ULL<<popcnt;
				for (ll i=0;i<lim;i++) {
					g[i]=0;
				}
				ll x=0;
				g[x]++;
				for (ll i=0;i<n;i++) {
					x^=((a[i]&mask)>>(t-1));
					g[x]++;
				}
				long long ans=0;
				need=need>>(t-1);
				for (ll wfirst=0;wfirst<lim;wfirst++) {
					long long wc=g[wfirst];
					long long ac=g[wfirst^need];
					ans += (wc*ac);
				}
				assert((ans%2)==0);
				ans/=2;
				final+=ans;
			}
			else {
				unordered_map<ll,ll> h;
				ll x=0;
				h[x]++;
				for (ll i=0;i<n;i++) {
					x^=a[i]&mask;
					h[x]++;
				}
				long long ans=0;
				for (auto &w: h) {
					long long wc=w.second;
					auto it=h.find(w.first^need);
					if (it==h.end()) continue;
					long long ac=it->second;
					//printf("%d %d. %d %d\n",w.first,w.first^need,wc,ac);
					ans += (wc*ac);
				}
				assert((ans%2)==0);
				ans/=2;
				final+=ans;
			}
		}
	}
	printf("%I64d\n",final);
}