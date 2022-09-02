#include <iostream>
#include <utility>
using namespace std;

pair<long long, pair<long long, long long>> ext_euc(long long a, long long b) {
	if (b == 0) return {a, {1, 0}};
	long long m = a / b;
	auto sub = ext_euc(b, a-m*b);
	return {sub.first, {sub.second.second, sub.second.first - m * sub.second.second}};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long n, a, b;
	cin >> n >> a >> b;
	auto sub = ext_euc(a, b);
	// ax + by = c
	// x and y are positive
	long long gd = sub.first;
	long long x = sub.second.first;
	long long y = sub.second.second;
	long long mult = n / gd;
	x *= mult;
	y *= mult;
	long long bd = b / gd;
	long long ad = a / gd;
	if (x < 0) {
		long long mult2 = -(x - (bd-1)) / bd;
		x += bd * mult2;
		y -= ad * mult2;
	}
	if (y < 0) {
		long long mult2 = -(y - (ad-1)) / ad;
		x -= bd * mult2;
		y += ad * mult2;
	}
	if (x < 0 || y < 0 || n != mult * gd) {
		cout << "-1\n";
	} else {
		for (long long j = 0; j < x; ++j) {
			for (long long i = j*a+1; i < j*a+a; ++i) {
				cout << i+1 << ' ';
			}
			cout << j*a+1 << ' ';
		}
		for (long long j = 0; j < y; ++j) {
			for (long long i = x*a+j*b+1; i < x*a+j*b+b; ++i) {
				cout << i+1 << ' ';
			}
			cout << x*a+j*b+1 << ' ';
		}
		cout << '\n';
	}
}