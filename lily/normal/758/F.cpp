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


LL power(LL x, LL k) {
	LL ret = 1;
	for (int i = 1; i <= k; i++) ret = ret * x;
	return ret;
}


int gcd(int a, int b) {
	if (b) return gcd(b, a % b);
	else return a;
}

LL n, l, r;

LL a[5005];


int main() {
	cin >> n >> l >> r;
	n--;
	if (!n) cout << r - l + 1 << endl;
	else if (n == 1) cout << LL(r - l + 1) * (r - l) << endl;
	else if (n > 23) cout << 0 << endl;
	else {
		a[0] = a[1] = 1;
		int cnt = 1;
		for (int i = 2; a[cnt] <= r; i++) {
			a[++cnt] = power(i, n);
		}
		LL ans = 0;
		for (int i = 1; i <= cnt; i++) {
			for (int j = i + 1; j <= cnt; j++) {
				if (gcd(i, j) == 1) {
					LL st = (l - 1) / a[i] + 1, ed = r / a[j];
					if (ed >= st) ans += ed - st + 1;
				}
			}
		}
		cout << ans * 2 << endl;
	}
	return 0;
}