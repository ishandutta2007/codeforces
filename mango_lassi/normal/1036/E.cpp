#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

const ll HUGE = (int)1e9 + 7;
const int N = 1000;
ll xs[N];
ll ys[N];
ll dx[N];
ll dy[N];

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll sgn(ll v) {
	return (v < 0 ? -1 : 1);
}

ll enc(ll x, ll y) {
	return x + y * HUGE;
}

bool onLine(int i, ll x, ll y) {
	x -= xs[i];
	y -= ys[i];
	if (0 > y * sgn(dy[i]) || abs(y) > abs(dy[i])) return false;
	if (0 > x * sgn(dx[i]) || abs(x) > abs(dx[i])) return false;
	return (x * dy[i] == y * dx[i]);
}

int main() {
	int n;
	cin >> n;
	
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		cin >> xs[i] >> ys[i] >> dx[i] >> dy[i];
		dx[i] -= xs[i];
		dy[i] -= ys[i];
		res += 1 + gcd(abs(dx[i]), abs(dy[i]));
	}

	for (int i = 0; i < n; ++i) {
		set<ll> colls;
		for (int j = i+1; j < n; ++j) {
			// When do two lines intersect?
			// Special cases: dx[i] = 0 or dy[i] = 0
			ll tx = -HUGE;
			ll ty = -HUGE;
			
			// dxs = xs[j] - xs[i]
			// dys = ys[j] - ys[i]
			// dds = dy[i]dxs - dx[i]dys
			// div = dy[j]dx[i] - dy[i]dx[j]

			// xs[i] + a * dx[i] = xs[j] + b * dx[j]
			// a = (b * dx[j] + dxs) / dx[i]
			// a = (b * dy[j] + dys) / dy[i]
			// dx[i] (b * dy[j] + dys) = dy[i] (b * dx[j] + dxs)
			// b * (dy[j]dx[i] - dy[i]dx[j]) = dy[i]dxs - dx[i]dys
			// b = dds / div
			
			// What happens when dx[i] == 0
			// tx = xs[j] + (dx[j] * dds) / div
			// tx = xs[j] + (dx[j] * (-dx[i] * dys)) / (dy[j] * dx[i])
			// tx = xs[j] + (dx[j] * (ys[i] - ys[j])) / dy[j]
			// ty = ys[j] + (dy[j] * dds) / div
			// ty = ys[j] + (dy[j] * (dy[i] * dxs)) / -(dy[i] * dx[j])
			// ty = ys[j] + (dy[j] * (xs[i] - xs[j])) / dx[j]
			// So tx is wrong, but ty is correct. Therefore we can just set tx = xs[i] :Dd

			ll dxs = xs[j] - xs[i];
			ll dys = ys[j] - ys[i];
			ll dds = dy[i] * dxs - dx[i] * dys;
			ll div = dy[j] * dx[i] - dy[i] * dx[j];
			// div == 0 -> They are parallel, but can't lie on the same line -> can't collide
			if (div == 0) continue;
			tx = xs[j] + (dx[j] * dds) / div;
			ty = ys[j] + (dy[j] * dds) / div;
			if (dx[i] == 0) tx = xs[i];
			if (dy[i] == 0) ty = ys[i];
	
			if (onLine(i, tx, ty) && onLine(j, tx, ty)) {
				colls.insert(enc(tx, ty));
			}
		}
		res -= colls.size(); // We decrement each collision point only once, since sets can't contain duplicates
	}
	cout << res << '\n';
}