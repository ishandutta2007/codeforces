#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;
vector<long long> pre;

int main() {
	scanf("%d", &n);
	a.resize(n+1);
	pre.resize(n+2, 0);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		pre[i+1] = pre[i] + a[i];
	}
	map<long long, int> m;
	int ans = 0;
	int prev = -1;
	for (int i = 1; i <= n+1; i++) {
		//printf("%lld\n", pre[i]);
		if (m[pre[i]] == 0) {
			m[pre[i]] = i;
		}
		else {
			if (prev > m[pre[i]]) {
				m[pre[i]] = i;
				continue;
			}
			ans++;
			prev = i-1;
			m[pre[i]] = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}