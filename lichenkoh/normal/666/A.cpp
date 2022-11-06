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
const ll MAXN=10000+2;
set<string> f[MAXN];
set<string> ans;
int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	ll n=s.length()-4;
	f[0].insert("");
	for (ll x=0;x<n;x++) {
		ll fsz=f[x].size();
		ll maxl=min(n-1-x,3LL);
		if (fsz==0) continue;
		else if (fsz==1) {
			string forbid=*(f[x].begin());
			for (ll len=2;len<=maxl;len++) {
				string t=s.substr(x,len);
				if (t==forbid) continue;
				if (f[x+len].size() < 2) {
					f[x+len].insert(t);
				}
				reverse(t.begin(),t.end());
				ans.insert(t);
			}
		}
		else {
			for (ll len=2;len<=maxl;len++) {
				string t=s.substr(x,len);
				if (f[x+len].size() < 2) {
					f[x+len].insert(t);
				}
				reverse(t.begin(),t.end());
				ans.insert(t);
			}
		}
	}
	cout<<ans.size()<<endl;
	for (auto &w:ans) {
		cout<<w<<endl;
	}
}