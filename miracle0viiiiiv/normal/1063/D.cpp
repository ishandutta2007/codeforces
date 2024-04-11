#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
/*
(n + a + b)x + r + a = k
nx + r + a <= k <= 2nx + r + a

a(x + 1) + bx = k - nx - r

1. n > k^1/3: check 
2. n < k^1/3: check a/b
*/
LL solve(LL n, LL r, LL k, LL mina)
{
	if(k < r) return -1;
	LL ans = -1;
	if(n > k / n / n) {
		if(k <= 2 * r) ans = max(ans, k - r + n - r);
		for(LL x = max((k - r * 2 - 1) / (2 * n) + 1, 1LL); x <= (k - r) / n; x ++) {
			LL a = (k - r) % x;
			if(a < mina) a += x;
			LL b = (k - r - a) / x - n - a;
			if(b < 0) continue;
			if(b > n - r) {
				LL t = (b - n + r - 1) / (x + 1) + 1;
				a += t * x;
				b -= t * (x + 1);
			}
			if(a <= r && b >= 0) ans = max(ans, a + b);
		}
	} else {
		for(LL a = mina; a <= r; a ++) for(LL b = 0; b <= n - r; b ++)
		if((k - r - a) % (n + a + b) == 0) ans = max(ans, a + b);
	}
	return ans;
}

int main()
{
	LL n, l, r, k;
	scanf("%I64d%I64d%I64d%I64d", &n, &l, &r, &k);
	r = (r - l + n) % n + 1;
	printf("%I64d\n", max(solve(n, r, k + 1, 1), solve(n, r, k, 0)));
	return 0;
}