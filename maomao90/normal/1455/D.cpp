#include <bits/stdc++.h>
using namespace std;

int t;
int n, x;
int a[505];
int ans;

bool isSorted() {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}
int getFirst() {
	for (int i = 0; i < n; i++) {
		if (a[i] > x) return i;
	}
	return -1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &x);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		ans = 0;
		while (!isSorted() && getFirst() != -1) {
			int first = getFirst();
			swap(a[first], x);
			ans++;
		}
		if (!isSorted()) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}