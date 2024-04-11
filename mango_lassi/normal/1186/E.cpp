#include <iostream>
using namespace std;
using ll = long long;

const int N = 1000;
ll ini[N][N];
int h, w;

// Q: Assume initial is size 1, 1. How many times has position x, y been flipped?
// A: popcount(x ^ y) times
// For a rectangle [ah, ah+h) x [bw, bw+w), it has been flipped popcount(a ^ b) times
bool flips(ll x, ll y) {
	return __builtin_popcountll((x / w) ^ (y / h)) & 1;
}
ll boxCount(ll x, ll y, ll x1, ll y1, ll x2, ll y2) {
	x1 = max(x1, x);
	y1 = max(y1, y);
	x2 = min(x2, x+w-1);
	y2 = min(y2, y+h-1);
	if (x2 < x1 || y2 < y1) return 0;
	x1 %= w; x2 %= w;
	y1 %= h; y2 %= h;
	bool f = flips(x, y);
	--x1;
	--y1;
	ll res = ini[y2][x2];
	if (x1 >= 0) res -= ini[y2][x1];
	if (y1 >= 0) res -= ini[y1][x2];
	if (x1 >= 0 && y1 >= 0) res += ini[y1][x1];
	if (f) res = ((x2 - x1) * (y2 - y1) - res);
	return res;
}

ll solve(ll x1, ll y1, ll x2, ll y2) {
	if (x2 < x1 || y2 < y1) return 0;

	ll xc1 = (x1 + (2*w-1)) / (2*w) * (2*w);
	ll yc1 = (y1 + (2*h-1)) / (2*h) * (2*h);
	ll xc2 = (x2+1) / (2*w) * (2*w) - 1;
	ll yc2 = (y2+1) / (2*h) * (2*h) - 1;
	if (xc1 < xc2) {
		ll res = (y2 - y1 + 1) * (xc2 - xc1 + 1) / 2;
		res += solve(x1, y1, xc1-1, y2);
		res += solve(xc2+1, y1, x2, y2);
		return res;
	} else if (yc1 < yc2) {
		ll res = (yc2 - yc1 + 1) * (x2 - x1 + 1) / 2;
		res += solve(x1, y1, x2, yc1-1);
		res += solve(x1, yc2+1, x2, y2);
		return res;
	} else {
		ll res = 0;
		ll x0 = x1 / w * w;
		ll y0 = y1 / h * h;
		for (ll x = x0; x <= x2; x += w) {
			for (ll y = y0; y <= y2; y += h) {
				res += boxCount(x, y, x1, y1, x2, y2);
			}
		}
		return res;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> h >> w >> q;
	// Calculate for each multiple of the matrix how many ones it has
	// Then find which sizes appear how many times inside the query rectangle

	for (int y = 0; y < h; ++y) {
		string row;
		cin >> row;
		for (int x = 0; x < w; ++x) {
			ini[y][x] = (row[x] == '1');
			if (y > 0) ini[y][x] += ini[y-1][x];
		}
	}
	for (int y = 0; y < h; ++y) {
		for (int x = 1; x < w; ++x) ini[y][x] += ini[y][x-1];
	}

	for (int qi = 0; qi < q; ++qi) {
		ll x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		--x1; --y1; --x2; --y2;
		ll res = solve(x1, y1, x2, y2);
		cout << res << '\n';
	}
}