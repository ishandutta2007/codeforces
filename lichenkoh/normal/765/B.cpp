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
	string a; cin>>a;
	ll n=a.length();
	ll used=-1;
	for (ll i=0;i<n;i++) {
		ll v=a[i]-'a';
		if (v>used+1) {
			cout<<"NO"<<endl;
			return 0;
		}
		if (v==used+1) {
			used++;
		}
	}
	cout<<"YES"<<endl;
}