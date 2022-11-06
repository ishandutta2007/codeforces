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
const ll mn=150+5;
string s[mn];
string ans[mn];
ll gid=0;
string getnextname() {
	++gid;
	string b="Aaaaaaaaaa";
	ll tmp=gid;
	for (ll x=9;x>=0;x--) {
		b[x]+=tmp%25;
		tmp/=25;
	}
	return b;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,k;
	cin>>n>>k;
	for (ll i=1;i<=n-k+1;i++) {
		cin>>s[i];
	}
	for (ll x=1;x<=n;x++) {
		ans[x]=getnextname();
	}
	for (ll x=1;x<=n-k+1;x++) {
		if (s[x]=="NO") {
			ans[x+k-1]=ans[x];
		}
	}
	for (ll x=1;x<=n;x++) {
		cout<<ans[x];
		if (x!=n) cout<<" ";
	}
	cout<<endl;
}