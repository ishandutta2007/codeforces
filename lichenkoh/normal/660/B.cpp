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
ll a[200][5];
ll nj[] = {3,1,2,0};
ll tj[] = {1,0,2,3};
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; cin>>n>>m;
	for (ll i=0;i<n;i++) {
		for (ll j=0;j<4;j++) a[i][j]=0;
	}
	{
		ll i=0;
		ll j=0;
		for (ll k=1;k<=m;k++) {
			a[i%n][j]=k;
			if (j==0) j=3;
			else if (j==3) {j=0; i++;}
			else if (j==1) j=2;
			else if (j==2) {j=1; i++;}
			if (i==n&&j==0) j=1;
		}
	}
	vector<ll> ans;
	for (ll i=0;i<n;i++) {
		for (ll t=0;t<4;t++) {
			ll j = tj[t];
			if (a[i][j]!=0) ans.PB(a[i][j]);
		}
	}
	for (auto &w:ans) {
		cout << w << " ";
	}
	cout<<endl;
}