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
char a[2][2][2];
vector<char> v[2];
int main() {
	ios_base::sync_with_stdio(false);
	for (ll i=0;i<2;i++) {
		for (ll x=0;x<2;x++) {
			for (ll y=0;y<2;y++) {
				cin>>a[i][x][y];
			}
		}
	}
	for (ll i=0;i<2;i++) {
		ll idx=0;
		if (a[i][0][0]!='X') v[i].PB(a[i][0][0]);
		if (a[i][0][1]!='X') v[i].PB(a[i][0][1]);
		if (a[i][1][1]!='X') v[i].PB(a[i][1][1]);
		if (a[i][1][0]!='X') v[i].PB(a[i][1][0]);
	}
	bool final=false;
	for (ll r=0;r<4;r++) {
		bool ok=true;
		ll y=r;
		for (ll x=0;x<3;x++) {
			if (v[0][x]!=v[1][y]) ok=false;
			y=(y+1)%3;
		}
		if (ok) {
			final=true;
		}
	}
	if(final) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}