#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define MAXN 100008
#define EPS 0.00000000000000000001L
typedef complex<ld> pt;
ld qx[MAXN], qy[MAXN];
ld sq(ld k) {
	return k*k;
}

ld sqdist(pt a, pt b) {
	return sq(a.real() - b.real()) + sq(a.imag() - b.imag());
}

ld dist(pt a, pt b) {
	return sqrt(sqdist(a, b));
}

ld dot(pt a, pt b) {
	return a.real() * b.real() + a.imag() * b.imag();
}

ld perp(pt v, pt w, pt p) {
	ld l2 = sqdist(v,w);
	if (fabs(l2) < EPS) return dist(p,v);
	ld t = dot(p-v,w-v)/l2;
	if (t < 0.0) return dist(p,v);
	else if (t > 1.0) return dist(p,w);
	pt proj = v + t*(w-v);
	return dist(p, proj);
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n;
	ld px, py;
	cin >> n >> px >> py;
	ld maxr = 0;
	for (ll i = 0; i < n; i++) {
		cin >> qx[i] >> qy[i];
		ld r = sq(px - qx[i]) + sq(py - qy[i]);
		maxr = max(maxr, r);
	}
	ld minr = maxr;
	for (ll i = 0; i < n; i++) {
		ll j = (i+1)%n;
		while (j<0) {j+=n;}
		pt v = pt(qx[i], qy[i]);
		pt w = pt(qx[j], qy[j]);
		pt p = pt(px, py);
		ld cand = perp(v,w,p);
		minr = min(minr, cand);
	}
	ld PI = atan(1)*4;
	ld ans = PI * (maxr - minr*minr);
	cout << std::fixed;
	cout.precision(300);
	cout << ans << endl;
}