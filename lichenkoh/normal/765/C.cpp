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
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#define fst first
#define snd second
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll k,a,b; cin>>k>>a>>b;
	ll aq=a/k,bq=b/k;
	ll ar=a%k,br=b%k;
	ll ans=0;
	if (ar!=0) {bq--; ans++;}
	if (br!=0) {aq--; ans++;}
	if (aq<0||bq<0) {
		cout<<-1<<endl;
	}
	else {
		ans+=aq+bq;
		cout<<ans<<endl;
	}
}