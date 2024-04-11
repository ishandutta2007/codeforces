# include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t, k, d;
	scanf("%d%d%d%d", &n, &t, &k, &d);
	n = (n + k - 1) / k;
	int a = n * t;

	int b = max(n * t, d);
	for(int i = 0; i <= n; ++i) {
		b = min(b, max(i * t + d, (n - i) * t));
	}

	puts(b < a ? "YES" : "NO");
}