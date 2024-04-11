/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef long long LL;
LL n, m, k, x, y;

LL work(LL left) {
	LL ret = 0;
	for (LL i = 0; i < n && left; i++)
		for (LL j = 0; j < m && left; j++) {
			left--;
			if (i == x && j == y) ret++;
		}
	for (LL i = n - 2; left; i--)
		for (LL j = 0; j < m && left; j++) {
			left--;
			if (i == x && j == y) ret++;
		}
	return ret;
}


int main() {
//	freopen("read.in", "r", stdin);
//	freopen("cmp.out", "w", stdout);
	cin >> n >> m >> k >> x >> y; x--, y--;
	if (n == 1) {
		cout << (k + m - 1) / m << " " << k / m << " " << k / m + (y < (k % m));
	}
	else if (n == 2) {
		cout << (k + m * 2 - 1) / (m * 2) << " " << k / (m * 2) << " " << k / (m * 2) + (x * m + y < (k % (2 * m)));
	}
	else {
		LL aloop = (n - 1) * m * 2;
		// in every loop :
		// 1 for first 1 for last 2 for mid
		LL s = k / aloop, left = k % aloop;
		//t1
		LL fir = s, mid = s * 2, las = s;
		if (left) {
			fir++;
			if (left > m) {
				mid++;
				if (left > (n - 1) * m) {
					las++;
					if (left > n * m) {
						mid++;
					}
				}
			}
		}
		cout << max(max(fir, mid), las) << " ";
		fir = s, mid = s * 2, las = s;
		if (left >= m) {
			fir++;
			if (left >= (n - 1) * m) {
				mid++;
				if (left >= n * m) {
					las++;
				}
			}
		}
		cout << min(min(fir, mid), las) << " ";
		if (x == 0 || x == n - 1) fir = s;
		else fir = s * 2;
		cout << fir + work(left);
	}
	return 0;
}