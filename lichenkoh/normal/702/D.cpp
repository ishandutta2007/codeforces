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
int main() {
	ios_base::sync_with_stdio(false);
	ll d,k,a,b,t; cin>>d>>k>>a>>b>>t;
	ld cs=((ld)k)/(k*a+t);
	ld fs=1.0/b;
	if (fs>=cs) {
		ll drive=min(d,k);
		ll walk=d-drive;
		ll ans=drive*a+walk*b;
		cout<<ans<<endl;
	}
	else {
		ll ans=0;
		ll initd=min(d,k);
		d-=initd; ans+=initd*a;
		ll cyc=d/k;
		ll left=d-cyc*k;
		ll cand1=cyc*(k*a+t)+left*b;
		ll cand2=cyc*(k*a+t)+t+left*a;
		ans+=min(cand1,cand2);
		cout<<ans<<endl;
	}
}