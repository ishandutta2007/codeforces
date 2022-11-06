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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll f[100],g[100],pt[100];
int main() {
	ios_base::sync_with_stdio(false);
	{
		f[1]=1989;
		f[2]=1999;
		f[3]=2099;
		f[4]=3099;
		ll ten=10000;
		for (ll x=5;x<15;x++) {
			f[x]=f[x-1]+ten;
			ten*=10;
		}
		g[1]=9;
		g[2]=99;
		g[3]=99;
		for (ll x=4;x<15;x++) {
			g[x]=f[x];
		}
		pt[1]=10;
		for (ll x=2;x<15;x++) {
			pt[x]=pt[x-1]*10;
		}
	}
	ll tests; cin>>tests;
	for (ll ii=0;ii<tests;ii++) {
		string s; cin>>s;
		s=s.substr(4,s.length()-4);
		ll slen=s.length();
		stringstream ss(s);
		ll n; ss>>n;
		ll ans=f[slen]+(n-g[slen]+pt[slen])%pt[slen];
		cout<<ans<<endl;
	}
}