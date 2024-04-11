#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int n;
int w[100005];
int in[100005];
priority_queue<int> pq;
ll ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ans = 0;
		assert(pq.empty());
		memset(in, 0, sizeof in);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &w[i]);
			ans += w[i];
		}
		for (int i = 1; i < n; i++) {
			int u, v; scanf("%d%d", &u, &v);
			in[u]++; in[v]++;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < in[i]; j++) {
				pq.push(w[i]);
			}
		}
		printf("%lld ", ans);
		for (int i = 2; i < n; i++) {
			int w = pq.top(); pq.pop();
			ans += w;
			printf("%lld ", ans);
		}
		printf("\n");
	}
	return 0;
}