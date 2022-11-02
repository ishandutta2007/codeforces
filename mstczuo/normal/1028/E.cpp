# include <bits/stdc++.h>
using namespace std;

int a[140582 + 10];
long long b[140582 + 10];

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	if(*max_element(a, a + n) == 0) {
		puts("YES");
		for(int i = 0; i < n; ++i) printf("%d ", 1);
		puts("");
		return 0;
	}
	a[n] = a[0];
	int p = -1;
	for(int i = 1; i <= n; ++i) {
		if(a[i] > a[i-1]) {
			p = i % n;
			break;
		}
	}
	if(p == -1) {
		puts("NO");
		return 0;
	}
	b[p] = a[p];
	for(int i = 1; i < n; ++i) {
		int j = (p + n - i) % n;
		int k = (j + 1) % n;
		b[j] = a[j] + b[k];

		int req = a[(j + n - 1) % n];
		while(b[j] <= req) b[j] += b[k];
	}
	puts("YES");
	for(int i = 0; i < n; ++i) {
		printf("%I64d ", b[i]);
	}
	b[n] = b[0];
	for(int i = 0; i < n; ++i) {
		if(b[i] % b[i+1] != a[i]) {
			for(;;);
		}
	}
	puts("");
	return 0;
}