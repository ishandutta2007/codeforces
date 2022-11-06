#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
vector<pair<ll,ll> > v;
int main() {
	ios_base::sync_with_stdio(false);
	string s; cin>>s;
	ll n=s.length();
	ll cnt=1;
	for (ll x=1;x<=n;x++) {
		if (x==n||s[x-1]!=s[x]) {
			v.PB(MP(s[x-1]-'a',cnt));
			cnt=1;
		}
		else cnt++;
	}
	ll vsz=v.size();
	for (ll x=0;x<vsz;x++) {
		ll nxt=(x==n-1)?-1:v[x+1].first;
		ll good=0;
		while (good==nxt||good==v[x].first) good++;
		char gb='a'+v[x].first;
		char gc='a'+good;
		ll k=v[x].second;
		for (ll t=0;t<k/2;t++) {
			printf("%c%c",gb,gc);
		}
		if (k%2) {
			printf("%c",gb);
		}
	}
	printf("\n");
}