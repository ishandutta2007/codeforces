#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	string s; cin >> s;
	char *a = new char[n+1];
	a[0] = -1;
	for (ll i = 1; i <= n; i++) {
		a[i] = (s[i-1] == '1') ? 1 : 0;
	}
	ll **f[3];
	for (ll k = 0; k < 3; k++) {
		f[k] = new ll*[n+1];
		for (ll i = 0; i <= n; i++) {
			f[k][i] = new ll[2];
			for (ll j = 0; j < 2; j++) {
				f[k][i][j] = 0;
			}
		}
	}
	ll ans = 0;
	for (ll k = 0; k < 3; k++) {
		f[k][0][0] = 0;
		f[k][0][1] = 0;
		for (ll x = 1; x <= n; x++) {
			for (ll j = 0; j < 2; j++) {
				f[k][x][j] = f[k][x-1][j];
			}
			for (ll j = 0; j < 2; j++) {
				if ((k == 0 || k == 2) && a[x] != j) {
					ll c = a[x];
					f[k][x][c] = max(f[k][x][c], f[k][x-1][j] + 1);
				}
				if ((k == 1) && a[x] == j) {
					ll c = a[x] ^ 1;
					f[k][x][c] = max(f[k][x][c], f[k][x-1][j] + 1);
				}
			}
			if (k >= 1) {
				for (ll j = 0; j < 2; j++) {
					f[k][x][j] = max(f[k][x][j], f[k-1][x][j]);
				}
			}
			for (ll j = 0; j < 2; j++) {
				//printf("%d %d %d: %d\n",k,x,j,f[k][x][j]);
				ans = max(ans, f[k][x][j]);
			}
		}
	}
	cout << ans << endl;
}