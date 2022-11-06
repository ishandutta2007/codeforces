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
	ll n; cin>>n;
	string home; cin>>home;
	ll out=0,in=0;
	for (ll i=0;i<n;i++) {
		string got; cin>>got;
		ll idx=got.find("->");
		string from=got.substr(0,idx);
		ll gl=got.length();
		string to=got.substr(idx+2,gl-(idx+2));
		//cout<<from<<":"<<to<<endl;
		if (from==home) out++;
		else in++;
	}
	//cout<<out<<","<<in<<endl;
	if (out==in) cout<<"home"<<endl;
	else cout<<"contest"<<endl;
}