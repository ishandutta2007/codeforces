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
	cin.tie(0);
	ll n,t; cin>>n>>t;
	string s; cin>>s;
	s = "0"+s;
	n++;
	t=min(t,n+1);
	ll end=n-1;
	ll f=-1;
	ll dec=-1;
	for (ll x=0;x<n;x++) {
		if (s[x]=='.') dec=x;
	}
	for (ll x=dec+1;x<n;x++) {
		if (s[x]>='5') {
			f=x-1; break;
		}
	}
	for (ll jj=0;jj<t;jj++) {
		if (f<0) break;
		if (f>=0&&f+1>dec) {
			if (s[f]=='.') f--;
			end=f;
			while(f>=0) {
				if (s[f]=='.') f--;
				s[f]++;
				if (s[f]<='9') break;
				s[f]='0';
				f--;
			}
		}
		for (ll x=f;x>=1;x--) {
			if (s[x]!='.' && s[x]>='5') {
				f=x-1; break;
			}
		}
	}
	ll start=0;
	if (s[start]=='0') start++;
	if (s[end]=='.') end--;
	string ans=s.substr(start,end-start+1);
	cout<<ans<<endl;
}