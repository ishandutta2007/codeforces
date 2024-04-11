#include <bits/stdc++.h>
#include <complex>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define PB push_back
#define INF 1000000000000LL
ld f[2002][2002][2][2];
ll a[2002], goleft[2002], goright[2002];
int main() {
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed;
	std::cout << std::setprecision(300);
	ll n, h; ld p;
	cin >> n; cin >> h; cin >> p;
	//ll *a = new ll[n+2];
	//ll *goleft = new ll[n+2];
	//ll *goright = new ll[n+2];
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = -INF;
	a[n+1] = INF;
	sort(a, a+n+2);
	// Find chains
	
	for (ll i = 0; i <= n+1; i++) {
		goleft[i] = i;
		goright[i] = i;
	}
	for (ll i = 2; i <= n; i++) {
		if (a[i] - h < a[i-1]) {
			goleft[i] = goleft[i-1];
		}
	}
	for (ll i = n-1; i >= 1; i--) {
		if (a[i] + h > a[i+1]) {
			goright[i] = goright[i+1];
		}
	}

	ld ans = 0;
	/*
	ld ****f = new ld***[n+2];
	for (ll x = 0; x <= n+1; x++) {
		f[x] = new ld**[n+2];
		for (ll y = 0; y <= n+1; y++) {
			f[x][y] = new ld*[2];
			for (ll xl = 0; xl < 2; xl++) {
				f[x][y][xl] = new ld[2];
				for (ll yl = 0; yl < 2; yl++) {
					f[x][y][xl][yl] = 0;
				}
			}
		}
	}
	*/
	f[1][n][0][0] = 1;
for (ll s = 0; s <= n-1; s++) {
for (ll x = 1; x <= 1+s; x++) {
ll spare = s - (x-1);
ll y = n - spare;
assert(1 <= x && x <= y && y <= n);
for (ll xr = 0; xr <= 1; xr++) {
for (ll yl = 0; yl <= 1; yl++) {
	// Push x left
	{
		ld q = 0.5 * p * f[x][y][xr][yl];
		f[x+1][y][0][yl] += q;
		ll takex = max(0LL,xr ? min(h, a[x] - (a[x-1]+h)) : min(h, a[x] - a[x-1]));
		ans += q * takex;
		//printf("%d %d %d %d ,",x,y,xr,yl);
		//cout << "Push x left  " << q << "," << takex << endl;
	}
	{
		// Push x right
		ll newx = goright[x];
		ld q = 0.5 * (1-p) * f[x][y][xr][yl];
		f[newx+1][y][1][yl] += q;
		ll takey = max(0LL, yl ? min(h, a[y+1]-h-a[y]) : min(h, a[y+1]-a[y]));
		ll take = min(a[newx] + h - a[x],
			a[y] - a[x] + takey);
		ans += q * take;
		//printf("%d %d %d %d ,",x,y,xr,yl);
		//cout << "Push x right " << q << "," << take << endl;
	}
	{
		// Push y left
		ll newy = goleft[y];
		ld q = 0.5 * p * f[x][y][xr][yl];
		f[x][newy-1][xr][1] += q;
		ll takex = max(0LL, xr ? min(h, a[x] - (a[x-1]+h)) : min(h, a[x] - a[x-1]));
		ll take = min(a[y] - a[newy] + h,
			a[y] - a[x] + takex);
		ans += q * take;
		//printf("%d %d %d %d ,",x,y,xr,yl);
		//cout << "Push y left  " << q << "," << take << endl;
	}
	{
		// Push y right
		ld q = 0.5 * (1-p) * f[x][y][xr][yl];
		f[x][y-1][xr][0] += q;
		ll takey = max(0LL, yl ? min(h, a[y+1]-h-a[y]) : min(h, a[y+1]-a[y]));
		ans += q * takey;
		//printf("%d %d %d %d ,",x,y,xr,yl);
		//cout << "Push y right " << q << "," << takey << endl;
	}
}
}
}
}
	cout << ans << endl;
}