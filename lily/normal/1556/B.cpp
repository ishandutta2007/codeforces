#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const long long INF = 1e18;
int n, a[N], b[N];
long long ans;
void check(int cnt) {
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		tot += b[i];
	}
	if (tot != cnt) return;
	queue <int> L[2];
	unordered_set <int> vis;
	for (int i = 1; i <= n; i++) {
		L[a[i]].push(i);
	}
	long long p = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		while (vis.count(j)) j++;
		if (a[j] == b[i]) {
			j++;
			L[b[i]].pop();
		}
		else {
			auto x = L[b[i]].front();
			vis.insert (x);
			p += x - i;
			L[b[i]].pop();
		}
	}
	ans = min(ans, p);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		scanf("%d", &n);
		ans = INF;
		int cnt = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i), a[i] %= 2, cnt += a[i];
	
		for (int i = 1; i <= n; i += 2) b[i] = 1, b[i + 1] = 0;
		check(cnt);
		for (int i = 1; i <= n; i += 2) b[i] = 0, b[i + 1] = 1;
		check(cnt);
		
		printf("%lld\n", ans == INF ? -1 : ans);
	}
}