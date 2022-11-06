#include <bits/stdc++.h>
#include <assert.h>
#define PB push_back
#define MP make_pair
#define UNDEF -1
using namespace std;
typedef long long ll;
ll a[101];
double f[2][100008];
int main() {
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed;
  	std::cout << std::setprecision(100);
	ll n,m; cin >> n; cin >> m;
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	f[0][0] = 1;
	ll mn1 = m-1;
	for (ll t = 0; t < n; t++) {
		ll lim = t * m;
		ll slim = (t+1) * m;
		ll c = t%2;
		ll s = (t+1)%2;
		for (ll x = 0; x <= slim; x++) {
			f[s][x] = 0;
		}
		for (ll x = t; x <= lim; x++) {
			double p = f[c][x]/mn1;
			f[s][x+1] += p;
			ll k = a[t];
			f[s][x+k] -= p;
			f[s][x+k+1] += p;
			f[s][x+m+1] -= p;
		}
		slim++;
		for (ll x = 1; x <= slim; x++) {
			f[s][x] += f[s][x-1];
			//cout << x << ":" << f[s][x] << " ";
		}
		//cout << endl;
	}
	ll s = n%2;
	double ans = 0;
	for (ll x = 0; x < sum; x++) {
		ans += f[s][x];
	}
	ans = ans * (m-1);
	ans = ans + 1;
	cout << ans << endl;
}