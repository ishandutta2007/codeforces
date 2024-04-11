#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(x) scanf("%d", &x)

#define N 201111

int n, k;

void work() {
	read(n); read(k);
	int al, ar, bl, br;
	read(al); read(ar); read(bl); read(br);
	if (al > bl) swap(al, bl), swap(ar, br);
	LL base = min(ar, br) - bl;
		LL lo = max(ar, br) - al;
		LL on = lo - base;
		
	if (bl <= ar) {
		on *= n;
		base *= n;
		if (k <= base) puts("0");
		else if (on >= k - base) printf("%lld\n", k - base);
		else {
			LL K = k - base;
			printf("%lld\n", K * 2 - on);
		}
	}
	else {
		LL b = bl - ar, ans = 2e9;
		for (int i = 1; i <= n; i++) {
			ans = min(ans, i * b + k + max(0ll, k - lo * i));
		}
		printf("%lld\n", ans);
	}
}

int main() {
	int T;
	read(T);
	while (T--) work();

}