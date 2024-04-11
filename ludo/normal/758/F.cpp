#include<bits/stdc++.h>
using namespace std;

int N, L, R, W;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxsqrtn = 3165; // 3162.2

// returns b^e.
// however, if b^e >= R, it returns -1
int pow(int b, int e)
{
	ll _b = b, r = 1;
	while (e) {
		// r, _b < R < 1e7
		if (e & 1) {
			r = r * _b; // r < 1e14
		}
		if (_b >= R || r >= R) return -1;
		e >>= 1;
		_b = _b * _b;
	}
	return (int) r;
}

int gcd(int a, int b) {
	while (b) a %= b, swap(a, b);
	return a;
}

int main()
{
	cin >> N >> L >> R;
	R++;
	W = R - L;

	if (N == 1) {
		cout << W << endl;
		return 0;
	}

	if (N == 2) {
		cout << (1LL * W * (W - 1)) << endl;
		return 0;
	}

	vector<pii> intervals;
	for (int d = 1, p = pow(d, N - 1); p != -1; p = pow(++d, N - 1)) {
		int lo = (L + p - 1) / p; // ceil
		int hi = (R + p - 1) / p;
		// cerr << d << ": " << p << ", [" << lo << ", " << hi << ")" << endl;
		intervals.emplace_back(lo, hi);
	}

	ll ret = 0;

	int sz = intervals.size();
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			if (i == 0 && j == 0) continue;
			int d = gcd(i + 1, j + 1);
			if (d != 1) continue;
			// i+1, j+1 are coprime
			int inter = min(intervals[i].y - intervals[j].x, intervals[j].y - intervals[i].x);
			if (inter > 0) {
				ret += 1LL * inter;
				// cerr << "d=" << (i + 1) << ", " << (j + 1) << " => " << inter << endl;
			}
		}
	}

	cout << ret << endl;
	return 0;
}