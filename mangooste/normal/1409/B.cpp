#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
 
	int t;
	cin >> t;
	while (t--) {
		int64_t a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		auto solve = [](int64_t a, int64_t b, int64_t x, int64_t y, int64_t n) {
            int64_t del = min(a - x, n);
             a -= del;
            n -= del;
            del = min(n, b - y);
            b -= del;
            n -= del;
            return a * b;
		};
		cout << min(solve(a, b, x, y, n), solve(b, a, y, x, n)) << '\n';
	}
}