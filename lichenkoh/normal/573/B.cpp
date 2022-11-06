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
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=1e5+4;
ll a[mn];
ll b[mn];
ll vans[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d",&n);
	for (ll i=1;i<=n;i++) scanf("%d",&b[i]);
	for (ll i=1;i<=n;i++) a[i]=min(b[i-1],min(b[i]-1,b[i+1]));
	{
		ll t=0;
		for (ll i=1;i<=n;i++) {
			t=min(t+1,a[i]);
			//printf("i:%d t:%d\n",i,t);
			vans[i]=t;
		}
	}
	{
		ll t=0;
		for (ll i=n;i>=0;i--) {
			t=min(t+1,a[i]);
			//printf("i:%d t:%d\n",i,t);
			chkmin(vans[i],t);
		}
	}
	ll final=0;
	for (ll i=1;i<=n;i++) chkmax(final,vans[i]);
	final++;
	printf("%d\n",final);
}