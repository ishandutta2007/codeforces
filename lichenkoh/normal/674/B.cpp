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
bool s[1008];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,k; cin>>n>>k;
	ll a,b,c,d; cin>>a>>b>>c>>d;
	if ((n<=4)||(k<n+1)) {
		cout<<-1<<endl; return 0;
	}
	for (ll i=0;i<1008;i++) s[i]=false;
	s[a]=true; s[b]=true; s[c]=true; s[d]=true;
	ll o=1;
	while(s[o])o++;
	s[o]=true;
	{
		cout<<a<<" ";
		for (ll x=1;x<=n;x++) {
			if (!s[x]) cout<<x<<" ";
		}
		cout<<c<<" "<<o<<" "<<d<<" "<<b<<endl;
	}
	{
		cout<<c<<" ";
		for (ll x=n;x>=1;x--) {
			if (!s[x]) cout<<x<<" ";
		}
		cout<<a<<" "<<o<<" "<<b<<" "<<d<<endl;
	}
}