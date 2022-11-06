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
map<string,ll> h;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	h["Tetrahedron"]=4;
	h["Cube"]=6;
	h["Octahedron"]=8;
	h["Dodecahedron"]=12;
	h["Icosahedron"]=20;
	ll n; cin>>n;
	ll ans=0;
	for (ll i=0;i<n;i++) {
		string s; cin>>s;
		//cout<<s<<endl;
		ans+=h[s];
	}
	cout<<ans<<endl;
}