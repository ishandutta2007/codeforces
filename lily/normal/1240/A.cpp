#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)


int Q, n, m;
int p[211111];
LL X, A, Y, B;
LL K;

bool ok(int mid) {
	LL x = mid / (A * B / __gcd(A, B)), y = mid / A, z = mid / B;
	y -= x; z -= x;
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		if (x) x--, ans += p[i] / 100 * (X + Y);
		else if (y) y--, ans += p[i] / 100 * X;
		else if (z) z--, ans += p[i] / 100 * Y;
	}
	return ans >= K;
}

void work() {
	read(n);
	for (int i = 1; i <= n; i++) read(p[i]);
	sort(p + 1, p + n + 1);
	reverse(p + 1, p + n + 1);
	cin >> X >> A >> Y >> B; cin >> K;
	if (X < Y) swap(X, Y), swap(A, B);
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (ok(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l > n ? -1 : l);
}

int main() {
	read(Q);
	while (Q--) work();

}