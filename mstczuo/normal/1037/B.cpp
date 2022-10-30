# include <bits/stdc++.h>
using namespace std;

int a[200010];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	long long ans = 0;
	if(a[n/2] >= m) {
		for(int i = 0; i <= n/2; ++i) ans += max(0, a[i] - m);
	} else {
		for(int i = n/2; i < n; ++i) ans += max(0, m - a[i]);
	}
	cout << ans << endl;
}