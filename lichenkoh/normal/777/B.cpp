#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
ll a[10],b[10];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; string as,bs; cin>>n>>as>>bs;
	for (ll i=0;i<n;i++) {
		ll x=as[i]-'0';a[x]++;
	}
	for (ll i=0;i<n;i++) {
		ll x=bs[i]-'0'; scanf("%d",&x);b[x]++;
	}
	{
		ll extra=0;
		ll flicks=0;
		for (ll x=9;x>=0;x--) {
			extra+=b[x];
			ll use=min(extra,a[x]);
			//printf("x:%d extra:%d a[x]:%d use:%d\n",x,extra,a[x],use);
			flicks+=max(0,a[x]-use);
			extra-=use;
		}
		printf("%d\n",flicks);
	}
	{
		ll extra=0,flicks=0;
		for (ll x=0;x<=9;x++) {
			ll use=min(extra,b[x]);
			extra-=use;
			flicks+=use;
			extra+=a[x];
		}
		printf("%d\n",flicks);
	}
}