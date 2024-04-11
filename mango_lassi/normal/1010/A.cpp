#include <iostream>
#include <iomanip>
using namespace std;
typedef long double ld;

const ld eps = (ld)1.0/1e8;
const int N = 1000;
int as[N];
int bs[N];
int m;

bool test(int n, ld v) {
	v = v - (ld)(v + m) / as[0];
	if (v < 0) return false;

	for (int i = 1; i < n; ++i) {
		v = v - (ld)(v + m) / bs[i];
		if (v < 0) return false;
		
		v = v - (ld)(v + m) / as[i];
		if (v < 0) return false;
	}

	v = v - (ld)(v + m) / bs[0];
	if (v < 0) return false;

	return true;
}

int main() {
	int n;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> as[i];
	for (int i = 0; i < n; ++i) cin >> bs[i];
	ld low = 0;
	ld high = 1e10;
	while(high - low > eps) {
		ld mid = (low + high) / 2;
		if (test(n, mid)) {
			high = mid;
		} else {
			low = mid;
		}
	}
	if (low > 1e9 + 5) {
		cout << "-1\n";
	} else {
		cout << fixed << setprecision(20) << low << '\n';
	}
}