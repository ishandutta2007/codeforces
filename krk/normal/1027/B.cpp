#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;

int main()
{
	scanf("%d %d", &n, &q);
	while (q--) {
		int r, c; scanf("%d %d", &r, &c);
		if ((r + c) % 2 == 0) {
			int fir = r / 2;
			int sec = r - 1 - fir;
			ll num = ll((n + 1) / 2) * fir + ll(n / 2) * sec + ll((c + 1) / 2);
			printf("%I64d\n", num); 
		} else {
			ll num = (ll(n) * n + 1) / 2;
			int fir = (r - 1) / 2;
			int sec = r - 1 - fir;
			num += ll((n + 1) / 2) * fir + ll(n / 2) * sec + ll((c + 1) / 2);
			printf("%I64d\n", num);
		}
	}
	return 0;
}