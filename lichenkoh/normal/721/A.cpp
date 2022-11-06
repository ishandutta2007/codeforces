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
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin>>n; string s; cin>>s;
	//s="W"+s;
	//n++;
	vector<ll> v;
	ll have=0;
	for (ll i=0;i<n;i++) {
		if (s[i]=='B') have++;
		else {
			if (have>0) v.PB(have);
			have=0;
		}
	}
	if (have>0) v.PB(have);
	cout<<(ll)v.size()<<endl;
	for (auto &w:v) cout<<w<<" ";
	if (v.size()>0) cout<<endl;
}