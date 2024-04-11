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
const ll MAXN=3e5+4;
ll notif[MAXN];
ll pt[MAXN];
queue<pair<ll,ll> > active;
int main() {
	ll n,q; scanf("%I64d %I64d",&n,&q);
	ll notifcount=1;
	ll ans=0;
	for (ll x=0;x<MAXN;x++) notif[x]=0;
	for (ll x=0;x<MAXN;x++) pt[x]=0;
	for (ll i=0;i<q;i++) {
		ll z,secondvar;
		scanf("%I64d %I64d",&z,&secondvar);
		if (z==1) {
			ll x=secondvar;
			notif[x]++;
			active.push(MP(x,notifcount));
			notifcount++;
		}
		else if (z==2) {
			ll x=secondvar;
			ans+=notif[x];
			notif[x]=0;
			pt[x]=notifcount-1;
		}
		else {
			ll t=secondvar;
			while(1) {
				if (active.empty()) break;
				pair<ll,ll> gg=active.front();
				ll app=gg.first, gotnotifcount=gg.second;
				if (gotnotifcount<=t) {
					if (gotnotifcount > pt[app]) {
						ans++;
						notif[app]--;
					}
					active.pop();
				}
				else break;
			}
		}
		ll final=notifcount-ans-1;
		printf("%I64d\n",final);
	}
}