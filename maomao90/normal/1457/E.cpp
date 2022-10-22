#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int c[500005];
priority_queue<ll> pq;
ll ans;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	sort(c, c + n, greater<int>());
	for (int i = 0; i < k + 1; i++) pq.push(0ll);
	for (int i = 0; i < n; i++) {
		ll bonus = pq.top(); pq.pop();
		ans += bonus;
		pq.push(bonus + c[i]);
	}
	printf("%lld\n", ans);
	return 0;
}