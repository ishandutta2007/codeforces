#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int K = 15;
const int M = 1 << K;
const int N = 100;

vector<int> as;

// Count number of set bits in lower K-bit part of as[i] ^ x
int lowc(int i, int x) {
	return __builtin_popcount((as[i] & (M - 1)) ^ x);
}

// Count number of set bits in upper K-bit part of as[i] ^ x
int highc(int i, int x) {
	return __builtin_popcount((as[i] >> K) ^ x);
}

// x < y?
bool comp(int x, int y) {
	int x_add = lowc(0, x);
	int y_add = lowc(0, y);
	for (int i = 1; i < as.size(); ++i) {
		int c1 = lowc(i, x) - x_add;
		int c2 = lowc(i, y) - y_add;
		if (c1 != c2) return c1 < c2;
	}
	return x < y;
}

// dir = 0: Find first with val >= tar
// dir = 1: Find last with val <= tar
int bins(const vector<int>& xs, int a, int b, int i, int tar, int dir) {
	int low = a - dir;
	int high = b + 1 - dir;
	while(low != high) {
		int mid = (low + high + dir) >> 1;
		int val = lowc(i, xs[mid]) - lowc(0, xs[mid]);
		if (dir == 0) {
			if (val >= tar) high = mid;
			else low = mid + 1;
		} else {
			if (val <= tar) low = mid;
			else high = mid - 1;
		}
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	as.resize(n);
	for (int i = 0; i < n; ++i) cin >> as[i];

	vector<int> xs(M);
	for (int x = 0; x < M; ++x) xs[x] = x;
	sort(xs.begin(), xs.end(), comp);

	for (int x = 0; x < M; ++x) {
		int add = highc(0, x);
		int a = 0;
		int b = M-1;
		for (int i = 1; i < n && a <= b; ++i) {
			// tar == val <=> lowc(0, x) + highc(0, x) == lowc(i, x) + highc(i, x)
			int tar = add - highc(i, x);
			a = bins(xs, a, b, i, tar, 0);
			b = bins(xs, a, b, i, tar, 1);
		}
		if (a <= b) {
			int res = (xs[a] | (x << K));
			cout << res << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}