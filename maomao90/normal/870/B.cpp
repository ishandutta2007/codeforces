#include <bits/stdc++.h>
using namespace std;

int n, k;
int mina, maxa;
int minl[100005], minr[100005], a[100005];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i == 0) mina = a[i], maxa = a[i];
		mina = min(a[i], mina);
		maxa = max(a[i], maxa);
	}
	minl[0] = a[0];
	minr[n - 1] = a[n - 1];
	for (int i = 1; i < n; i++) minl[i] = min(minl[i - 1], a[i]);
	for (int i = n - 2; i >= 0; i--) minr[i] = min(minr[i + 1], a[i]);
	if (k == 1) printf("%d\n", mina);
	else if (k == 2) {
		int ans = minl[0];
		for (int i = 1; i < n; i++) {
			ans = max(max(minl[i - 1], minr[i]), ans);
		}
		printf("%d\n", ans);
	}
	else printf("%d\n", maxa);
	return 0;
}