#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, d, t;

int main()
{
	cin >> k >> d >> t; t *= 2;
	ll my = k / d * d;
	if (my < k) my += d;
	d = my;
	ll one = d + k;
	ll tim = t / one * d;
	t %= one;
	if (2 * k >= t) {
		tim += t / 2;
		printf("%I64d.%d\n", tim, t % 2 != 0? 5: 0);
	} else {
		t -= 2 * k; tim += k;
		tim += t;
		printf("%I64d.0\n", tim);
	}
	return 0;
}