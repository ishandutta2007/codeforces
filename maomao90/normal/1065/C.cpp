#include <bits/stdc++.h>
using namespace std;

int n, k;
int h[200005];
int ans;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &h[i]);
	sort(h, h + n, greater<int>());
	long long cur = 0;
	for (int i = 1; i < n; i++) {
		cur += (long long) (h[i - 1] - h[i]) * i;
		while (cur >= k) {
			ans++;
			int remh = (cur - k) / i;
			if ((cur - k) % i != 0) remh++;
			cur = (long long) remh * i;
		}
	}
	if (cur > 0) ans++;
	printf("%d\n", ans);
	return 0;
}