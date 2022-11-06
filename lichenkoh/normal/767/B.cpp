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
const ll mn=1e5+4;
map<ll,ll> h;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll start,finish,spend; scanf("%lld%lld%lld",&start,&finish,&spend);
	ll n; scanf("%lld",&n);
	h[finish-spend+1]=0;
	for (ll i=1;i<=n;i++) {
		ll v;
		scanf("%lld",&v);
		h[v]++;
	}
	ll inq=0;
	pll final=MP(INF,INF);
	for (auto &w:h) {
		ll now=w.fst,numvis=w.snd;
		ll cand=now-1;
		ll endt=max(start+inq*spend,cand);
		if (endt+spend<=finish) {
			if (endt<now) chkmin(final,MP(0ll, cand));
			ll wait=endt-cand;
			chkmin(final,MP(wait, cand));
		}
		inq+=numvis;
	}
	printf("%lld\n",final.snd);
}