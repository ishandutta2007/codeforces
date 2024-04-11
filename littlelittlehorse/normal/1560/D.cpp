#include<bits/stdc++.h>

using namespace std;

int test, c[1001], d[1001];

int main(){
	scanf("%d", &test);
	for (; test--; ) {
		int n;
		scanf("%d", &n);
		int cnt = 0;
		for (int m = n; m; c[++cnt] = m % 10, m /= 10);
		for (int i = 1, j = cnt; i < j; i++, j--)
			swap(c[i], c[j]);
		long long cur = 1;
		int ans = 1 << 30;
		for (int i = 1; i <= 63; i++) {
			int tot = 0;
			for (long long m = cur;  m; d[++tot] = m % 10, m /= 10);
			for (int j = 1, k = tot; j < k; j++, k--)
				swap(d[j], d[k]);
			int l = 1;
			for (int j = 1; j <= cnt; j++) {
				if (l <= tot && d[l] == c[j])
					++l; 
			}
			ans = min(ans, tot - l + 1 + cnt - l + 1);
			cur *= 2;
		}
		printf("%d\n", ans); 
	}
}