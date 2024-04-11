#include <iostream>
#include <vector>
#include <algorithm>

const long long inf = 1e9;
std::vector<long long> ext;

long long pow(long long a, long long b) {
	if (b & 1) {
		if (b == 1) return a;
		return a * pow(a, b-1);
	} else {
		if (b == 0) return 1;
		long long res = pow(a, b >> 1);
		return res * res;
	}
}
bool check(long long a, long long b, long long h, long long w) {
	if (((a <= h) && (b <= w)) || ((b <= h) && (a <= w))) {
		return true;
	}
	return false;
}
long long brute(long long a,long long b,long long h,long long w, int i) {
	if (check(a,b,h,w)) {
		return i;
	}
	if (i == (int)ext.size()) {
		return inf;
	}
	int j = i+1;
	for (; j < (int)ext.size(); ++j) {
		if (ext[j] != ext[i]) {
			break;
		}
	}
	long long mult = ext[i];
	for (int s = 1; s < j - i; ++s) {
		for (int k = 0; k <= s; ++k) {
			if (check(a,b,h*pow(mult, k), w*pow(mult, s-k))) {
				return i + s;
			}
		}
	}
	long long min = inf;
	for (int k = 0; k <= j - i; ++k) {
		min = std::min(brute(a,b,h * pow(mult, k), w * pow(mult, j-i-k), j), min);
	}
	return min;
}

int main() {
	long long a, b, h, w, n;
	std::cin >> a >> b >> h >> w >> n;
	for (int i = 0; i < n; ++i) {
		long long d;
		std::cin >> d;
		ext.push_back(-d);
	}
	std::sort(ext.begin(), ext.end());
	for (int i = 0; i < (int)ext.size(); ++i) {
		ext[i] = -ext[i];
	}
	long long res = brute(a,b,h,w,0);
	if (res == inf) {
		std::cout << "-1\n";
	} else {
		std::cout << res << '\n';
	}
}