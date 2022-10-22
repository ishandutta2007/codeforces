#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int t, n, k;
priority_queue <int> pq;
int w[200005];
long long ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			pq.push(a);
		}
		for (int i = 0; i < k; i++) scanf("%d", &w[i]);
		sort(w, w + k);
		for (int i = 0; i < k; i++) {
			ans += pq.top();
			if (w[i] == 1) ans += pq.top();
			pq.pop(); w[i]--;
		}
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < w[i]; j++) {
				if (j == w[i] - 1) ans += pq.top();
				pq.pop();
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}