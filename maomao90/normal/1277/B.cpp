#include <cstdio>
#include <queue>

using namespace std;

int t;
int n;
priority_queue <int> pq;
int ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			pq.push(a);
		}
		int prev = -1;
		while (!pq.empty()) {
			int cur = pq.top(); pq.pop();
			if (cur == prev) {
				pq.push(cur / 2);
			} else if (cur % 2 == 0) {
				pq.push(cur / 2);
				prev = cur;
				ans++;
			}
		}
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}