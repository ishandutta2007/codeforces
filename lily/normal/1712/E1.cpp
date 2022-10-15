#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)


LL lcm(LL x, LL y) {
	return x / gcd(x, y) * y;
}

void work() {
	int l, r;
	scanf("%d%d", &l, &r);
/*	for (int i = l; i <= r; i++) {
		for (int j = l; j < i; j++) {
			for (int k = l; k < j; k++) if (lcm(lcm(i, j), k) < i + j + k) {
				if (lcm(lcm(i, j), k) > i) {
					cerr << (double)i / j << " " << (double)i / k << " " << (double) lcm(lcm(i, j), k) / i<< endl;
				}
			}
		}
	}*/ 
	vector <int> b(r + 1);
	for (int i = l; i <= r; i++) {
		for (int j = i + i; j <= r; j += i) {
			b[j]++;
		}
	}
	LL ans = 0;
	for (int i = l; i <= r; i++) {
		ans += b[i] * (b[i] - 1ll) / 2;
	}
	LL tot = LL(r - l + 1) * LL(r - l) * LL(r - l - 1) / 3 / 2; 
	ans = tot - ans;

	// 1.5 2
	// 1.5 2.5
	for (int i = 2 * l; i <= r; i++) {
		// 1.5 2.5 2
		//	1.5 2 2
		if (i % 6 == 0 && lcm(i / 3 * 2, i / 2) == 2 * i) ans --;  
		if (i / 5 * 2 >= l && i % 15 == 0 && lcm(i / 3 * 2, i / 5 * 2) == 2 * i) ans --;
	}
	printf("%lld\n", ans);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}