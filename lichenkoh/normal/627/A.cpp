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
const ll MAXN = 64;
ll f[MAXN][2][4];
int main() {
	ios_base::sync_with_stdio(false);
	ll s,t; cin >> s >> t;
	ll n=60;
	for (ll i=0;i<=n;i++) {
		for (ll k=0;k<2;k++) {
			for (ll z=0;z<4;z++) {
				f[i][k][0]=0;
			}
		}
	}
	f[0][0][0]=1;
	for (ll i=1;i<=n;i++) {
		ll sum = (s>>(i-1))&1;
		ll xo = (t>>(i-1))&1;
		for (ll c=0;c<2;c++) {
			for (ll a=0;a<2;a++) {
				for (ll b=0;b<2;b++) {
					ll r=(a+b+c > 1)?1:0;
					if (((a^b) == xo) && ((a+b+c)%2 == sum)) {
						for (ll z=0;z<4;z++) {
							ll nz=z;
							if (a!=0) nz|=1;
							if (b!=0) nz|=2;
							f[i][r][nz] += f[i-1][c][z];
							//if (f[i-1][c][z] != 0) {printf("%d %d: %d,%d,%d->%d,%d,%d:%d\n",a,b,i-1,c,z,i,r,nz,f[i-1][c][nz]);}
						}
					}
				}
			}
		}
	}
	ll ans = f[n][0][3];
	cout << ans << endl;


}