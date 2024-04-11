#include <bits/stdc++.h>
using namespace std;

int tc;
int n;

int main() {
	scanf("%d", &tc);
	for (int cas = 1; cas <= tc; cas++) {
		scanf("%d", &n);
		vector<int> a, b, c;
		a.resize(n); b.resize(n); c.resize(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) scanf("%d", &b[i]);
		for (int i = 0; i < n; i++) scanf("%d", &c[i]);
		int prev = -1;
		int fir = -1;
		for (int i = 0; i < n-1; i++) {
			if (a[i] != prev) {
				printf("%d ", a[i]);
				prev = a[i];
				if (fir == -1) fir = a[i];
			}
			else {
				printf("%d ", b[i]);
				prev = b[i];
			}
		}
		if (a[n-1] != prev && a[n-1] != fir) printf("%d\n", a[n-1]);
		else if (b[n-1] != prev && b[n-1] != fir) printf("%d\n", b[n-1]);
		else if (c[n-1] != prev && c[n-1] != fir) printf("%d\n", c[n-1]);
	}
	return 0;
}