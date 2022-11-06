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
const ll INF=1e18+4;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
ll dp[55];
ll f(ll n) {
	if (n<0) return 0;
	if (dp[n]!=-1) return dp[n];
	ll ans=f(n-1)+f(n-2);
	if (ans>=INF) ans=INF;
	return dp[n]=ans;
}
vll solve(ll n, ll k) {
	memset(dp,-1,sizeof dp);
	dp[0]=1;
	--k;
	ll x=0;
	vll v;
	while(1) {
		if (x>=n) break;
		ll lo=f(n-x-1);
		if (k<lo) {
			v.PB(x);
			x++;
		}
		else{
			k-=lo;
			v.PB(x+1);
			v.PB(x);
			x+=2;
		}
	}
	return v;
}
void test(ll n) {
	bool seen[55];
	vector<ll> v;
	for (ll x=0;x<n;x++) v.PB(x);
	vector<vll> vall;
	do {
		memset(seen,0,sizeof seen);
		vector<vll> all;
		for (ll x=0;x<n;x++) {
			if (seen[x]) continue;
			vll cyc;
			seen[x]=true;
			cyc.PB(x);
			ll y=v[x];
			if (y!=x) {
				while(y!=x) {
					cyc.PB(y);
					seen[y]=true;
					y=v[y];
				}
			}
			pll best=MP(-1ll,-1ll);
			for (ll i=0;i<cyc.size();i++) chkmax(best,MP(cyc[i],i));
			//for (auto &w:cyc) printf("%lld ",w);
			//printf(" end partial (%lld). ",best.snd);
			vll cyc2;
			ll csz=cyc.size();
			for (ll i=0;i<cyc.size();i++) {
				cyc2.PB(cyc[(i+best.snd)%csz]);
			}
			all.PB(cyc2);
		}
		sort(all.begin(),all.end());
		vll final;
		for (auto &x:all) for (auto &y:x) final.PB(y);
		if (final==v) {
			vall.PB(final);
		}
	} while(next_permutation(v.begin(),v.end()));
	for (ll k=1;k<=vall.size();k++) {
		assert(solve(n,k)==vall[k-1]);
	}
	printf("Passed %lld\n",n);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//for (ll k=1;k<=7;k++) test(k);
	ll n,k; cin>>n>>k;
	vll v=solve(n,k);
	for (auto &w:v) printf("%lld ",w+1);
	printf("\n");
}