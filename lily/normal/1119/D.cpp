#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)

#define N 100005
#define M 1000000000000000001
int n, q;
LL s[N];

LL a[N], b[N];
void init() {
	sort(s, s + n);
	for (int i = 1; i < n; i++) {
		a[i] = s[i] - s[i - 1];
	}
	sort(a + 1, a + n);
	for (int i = 1; i < n; i++) {
		b[i] = b[i - 1] + (a[i] - a[i - 1]) * LL(n - i + 1);
	}
}

LL solve(LL x) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (a[mid] <= x) l = mid;
		else r = mid - 1;
	}
	return b[l] + (x - a[l]) * LL(n - l);
}


int main() {
	read(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", s + i);
	}
	init();
	read(q);
	for (int i = 1; i <= q; i++) {
		LL l, r;
		scanf("%lld%lld", &l, &r);
		LL x = r - l + 1;
		printf("%lld ", solve(x));
	}


	return 0;
}