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
	string s; cin>>s;
	ll n=s.length();
	ll start=0;
	for (auto &w:s) {
		if (w!='a') {
			w--;
			start=1;
		}
		else if (start) break;
	}
	if (start==0) {
		s[n-1]='z';
	}
	cout<<s<<endl;
}