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
const ll mn=1e5+4;
string s[mn][2];
ll c[mn];
ll f[mn][2];
const ll INF=1e18;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n; cin>>n;
	for (ll i=0;i<n;i++) cin>>c[i];
	for (ll i=0;i<n;i++) cin>>s[i][0];
	for (ll i=0;i<n;i++) {s[i][1]=s[i][0]; reverse(s[i][1].begin(),s[i][1].end());}
	
	for (ll x=0;x<=n;x++) for (ll k=0;k<2;k++) f[x][k]=INF;
	f[0][0]=0;
	f[0][1]=c[0];
	for (ll x=1;x<n;x++) {
		for (ll st=0;st<2;st++) {
			for (ll e=0;e<2;e++) {
				if (s[x-1][st]<=s[x][e]) {
					ll cost=e?c[x]:0;
					chkmin(f[x][e],f[x-1][st]+cost);
				}
			}
		}
	}
	ll ans=min(f[n-1][0],f[n-1][1]);
	if (ans>=INF) {
		cout<<-1<<endl;
	}
	else cout<<ans<<endl;
}