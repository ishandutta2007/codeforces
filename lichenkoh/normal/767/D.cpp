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
const ll INF=1e9+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=2e6+2;
ll n,m,kk;
long long k;
pll origs[mn];
ll f[mn],s[mn];
const ll mx=1e7+2;
ll a[mx];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld%lld%lld",&n,&m,&kk);
	k=kk;
	for (ll i=0;i<n;i++) scanf("%lld",&f[i]);
	for (ll i=0;i<m;i++) scanf("%lld",&s[i]);
	for (ll i=0;i<m;i++) origs[i]=MP(s[i],i);
	sort(s,s+m);
	for (ll i=0;i<n;i++) a[f[i]]++;
	for (ll x=1;x<mx;x++) a[x]+=a[x-1];
	ll have=k;
	for (ll x=0;x<mx;x++) {
		a[x]=have-a[x];
		if (a[x]<0) {printf("-1\n"); return 0;}
		have+=k;
	}
	for (ll x=mx-2;x>=0;x--) chkmin(a[x],a[x+1]);
	ll ans=0;
	for (ll i=0;i<m;i++) {
		ll x=s[i];
		if (a[x]-ans>0) {
			ans++;
		}
	}
	sort(origs,origs+m);
	printf("%lld\n",ans);
	for (ll i=0;i<ans;i++) printf("%lld ",origs[m-1-i].snd+1);
	printf("\n");
}