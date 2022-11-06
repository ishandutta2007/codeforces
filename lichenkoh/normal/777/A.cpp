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
ll a[3];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,x; cin>>n>>x;
	if (n>1000) n%=24; n+=24;
	for (ll y=0;y<3;y++) {
		memset(a,0,sizeof a);
		a[y]=1;
		for (ll i=0;i<n;i++) {
		if (i%2==0) {
			swap(a[0],a[1]);
		}
		else swap(a[1],a[2]);			
		}
		if (a[x]) {
			printf("%lld\n",y);
			return 0;
		}
	}
}