#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1010;
int n,a;

int main() {
	scanf("%d", &n);
	int l = 1, r = n, mid;
	while (l < r - 1) {
		mid = (l + r) >> 1;
		printf("+ %d\n", n - mid);
		fflush(stdout);
		int val;
		scanf("%d", &val);
		if (val == a) r = mid;
		else l = mid;
		l = (l + n - mid) % n;
		r = (r + n - mid) % n;
		if (r == 0) r = n;
		a = val;
	}
	printf("! %d\n", a * n + l);
	return 0;
}