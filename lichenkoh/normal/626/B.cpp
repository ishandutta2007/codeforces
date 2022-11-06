#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll MAXN = 401;
bool f[MAXN][MAXN][MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	for (ll x=0;x<MAXN;x++) {
		for (ll y=0;y<MAXN;y++) {
			for (ll z=0;z<MAXN;z++) {
				f[x][y][z]=false;
			}
		}
	}
	ll n; cin >> n;
	string s; cin >> s;
	ll ix=0;
	ll iy=0;
	ll iz=0;
	for (ll i=0;i<n;i++) {
		if (s[i]=='B') ix++;
		else if (s[i]=='G') iy++;
		else if (s[i]=='R') iz++;
		else assert(false);
	}
	f[ix][iy][iz]=true;
	for (ll len=n;len>=0;len--) {
		for (ll x=0;x<=len;x++) {
			for (ll y=0;y<=len-x;y++) {
				ll z=len-x-y;
				if (f[x][y][z]) {
					if (x-2>=0) f[x-1][y][z]=true;
					if (y-2>=0) f[x][y-1][z]=true;
					if (z-2>=0) f[x][y][z-1]=true;
					if (y-1>=0&&z-1>=0) f[x+1][y-1][z-1]=true;
					if (x-1>=0&&z-1>=0) f[x-1][y+1][z-1]=true;
					if (x-1>=0&&y-1>=0) f[x-1][y-1][z+1]=true;
				}
			}
		}
	}
	string ans = "";
	if (f[1][0][0]==true) {ans += "B";}
	if (f[0][1][0]==true) {ans += "G";}
	if (f[0][0][1]==true) {ans += "R";}
	cout << ans << endl;
}