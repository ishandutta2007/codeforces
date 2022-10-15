#include <bits/stdc++.h>
using namespace std;



int n, m, K;

int a[100005], b[100005];

int main() {
	cin >> n >> m >> K;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (i > 1) b[i - 1] = a[i] - a[i - 1] - 1;
	}
	int ans = a[n] - a[1] + 1;
	sort(b + 1, b + n);
	reverse(b + 1, b + n);
	for (int i = 1; i <= min(K - 1, n - 1); i++) {
		ans -= b[i];
	}
	cout << ans << endl;
}