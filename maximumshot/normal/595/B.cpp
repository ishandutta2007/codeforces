#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

ll gcd (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
 
bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}

ll up(ll u, ll v) {
	if(v < 0) u *= -1, v *= -1;

	// u / v

	if(u >= 0) {
		return u / v + (u % v != 0);
	}else {
		return u / v;
	}
}

ll down(ll u, ll v) {
	if(v < 0) u *= -1, v *= -1;

	if(u >= 0) {
		return u / v;
	}else {
		return u / v - (u % v != 0);
	}
}

bool solve()
{
	int n, k;

	scanf("%d %d", &n, &k);

	vec< ll > a(n / k + 1), b(n / k + 1);

	for(int i = 1;i <= n / k;i++) {
		int x;
		scanf("%d", &x);
		a[i] = x;
	}

	for(int i = 1;i <= n / k;i++) {
		int x;
		scanf("%d", &x);
		b[i] = x;
	}

	ll ans = 1, value = 1;

	for(int i = 0;i < k;i++) value *= 10ll;

	// value = 10 ^ k

	for(int i = 1;i <= n / k;i++) {
		
		vec< vec< ll > > dp(k + 1, vec< ll >(10, 0));

		ll t = value / a[i] - (value % a[i] == 0);
		ll A, B, C, x0, y0, g;
		A = -1ll;
		B = a[i];
		C = b[i] * value / 10ll;

		if(!find_any_solution(A, B, C, x0, y0, g)) {
			ans = (ans * (t + 1)) % base;
		}else {
			ll l, r;
			
			l = max(up(-x0, B / g), up(y0, A / g));
			r = min(down(value / 10 - 1 - x0, B / g), down(y0 - t, A / g));
/*
			cout << up(-x0, B / g) << " " << up(y0 - t, A / g) << " " << down(value / 10 - 1 - x0, B / g) << " " << down(y0, A / g) << "\n";

			cout << x0 << " " << y0 << " " << g << " | "; 
			cout << l << " .. " << r << '\n'; */

		

			if(l <= r) ans = (ans * (t + 1 - (r - l + 1))) % base;
			else ans = (ans * (t + 1)) % base;
		}
	}
	
	cout << ans << '\n';

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}