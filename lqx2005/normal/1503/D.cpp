#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int p[N], q[N], cnt[2];
int main() {
	cin >> n;
	int flag = 0;
	for(int i = 1, a, b; i <= n; i++) {
		scanf("%d%d", &a, &b);
		int c = max(a, b) - n - 1;
		if(c < 0) {
			flag = 1;
			continue;
		}
		p[c] = n - min(a, b);
		q[c] = a > b;
	}
	if(flag) return printf("-1\n"), 0;
	int inc = -1, dec = -1, ans = 0;
	for(int i = 0; i < n; i++) {
		if(inc < p[i]) {
			inc = p[i];
			cnt[q[i]]++;
		} else {
			if(dec > p[i]) return printf("-1\n"), 0;
			dec = p[i];
			cnt[q[i] ^ 1]++;
		}
		if(i == inc) {
			ans += min(cnt[0], cnt[1]);
			cnt[0] = cnt[1] = 0;
		}
	}
	printf("%d\n", ans);
    return 0;
}