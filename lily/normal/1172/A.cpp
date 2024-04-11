#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mp(a, b) make_pair
#define x first
#define y second
#define read(x) scanf("%d", &x)
#define readl(x) scanf("%lld", &x)
#define readd(x) scanf("%lf", &x)

#define N 602025

int n;
int a[N], b[N];
int hand[N];

bool ok(int x) {
	for (int i = 0; i <= n ;i++) hand[i] = 0;
	for (int i = 1; i <= n; i++) {
		hand[a[i]]++;
	}
	int bh = 0;
	for (int i = 1; i <= x; i++) {
		hand[b[i]]++;
		b[(++bh) + n] = 0;
		if (hand[0]-- == 0) return 0;
	}
	int start = 1;
	if (hand[1]) {
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (b[bh + i] == 1) {
				for (int j = i; j <= n; j++) {
					if (b[bh + j] != j - i + 1) {
						return 0;
					}
				}
				start = n - i + 1 + 1;
				break;
			}
		}
	}
	for (int i = start; i <= n; i++) {
		if (hand[i] < 1) {
			return 0;
		}
		hand[i] = 0;
		hand[b[++bh]]++;
	}
	return 1;
}

int ck(int x) {
	for (int i = 0; i <= n ;i++) hand[i] = 0;
	for (int i = 1; i <= n; i++) {
		hand[a[i]]++;
	}
	int bh = 0;
	for (int i = 1; i <= x; i++) {
		hand[b[i]]++;
		b[(++bh) + n] = 0;
		hand[0]--;
	}
	int start = 1;
	if (hand[1]) {
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (b[bh + i] == 1) {
				for (int j = i; j <= n; j++) {
					if (b[bh + j] != j - i + 1) {
						return 0;
					}
				}
				start = n - i + 1 + 1;
			}
		}
	}
	for (int i = start; i <= n; i++) {
		if (hand[i] < 1) {
			return 0;
		}
		hand[i] = 0;
		hand[b[++bh]]++;
	}
	return bh;
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(b[i]);

	if (ok(0)) {
		printf("%d\n", ck(0));
		return 0;
	}
	int l = 0, r = n;
	
	while (l < r) {
		int mid = (l + r) >> 1;
		if (ok(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", ck(l));
}