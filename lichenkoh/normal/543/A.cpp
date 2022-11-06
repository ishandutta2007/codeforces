#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
ll f[502][502];
ll a[502];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll plim,linelim,blim,MOD; cin>>plim>>linelim>>blim>>MOD;
	for (ll i=0;i<plim;i++) cin>>a[i];
	memset(f,0,sizeof f);
	f[0][0]=1;
	for (ll p=0;p<plim;p++) {
		//printf("p:%lld a[p]:%lld blim:%lld\n",p,a[p],blim);
		//assert(1<=linelim);
		for (ll l=1;l<=linelim;l++) {
			//assert(a[p]<=blim);
			for (ll b=a[p];b<=blim;b++) {
				f[l][b]+=f[l-1][b-a[p]];
				//printf("p:%lld l:%lld b:%lld f:%lld\n",p,l,b,f[l][b]);
				f[l][b]%=MOD;
			}
		}
	}
	ll final=0;
	for (ll b=0;b<=blim;b++) final=(final+f[linelim][b])%MOD;
	printf("%lld\n",final);
}