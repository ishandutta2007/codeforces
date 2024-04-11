#include <cstdio>
#include <queue>
#include <utility>
#include <tuple>
#include <vector>

using namespace std;

typedef pair <int, int> ii;

int n, m;
int w[100005];
vector <int> partner[100005];
vector <int> eat[100005];
int cnt[100005];
bool added[200005];
bool visited[100005];
priority_queue <ii> pq;
vector <int> ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		cnt[x]++, cnt[y]++;
		eat[x].push_back(i);
		eat[y].push_back(i);
		partner[x].push_back(y);
		partner[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] != 0) pq.emplace(w[i] - cnt[i], i);
	}
	while (!pq.empty()) {
		int diff, cur; tie(diff, cur) = pq.top(); pq.pop();
		if (diff != w[cur] - cnt[cur]) continue;
		//printf("%d %d\n", cur, diff);
		if (diff < 0) {
			printf("DEAD\n");
			return 0;
		}
		visited[cur] = true;
		for (int v : eat[cur]) {
            if (added[v]) continue;
            added[v] = true;
            ans.push_back(v);
		}
		for (int v : partner[cur]) {
            if (visited[v]) continue;
			cnt[v]--;
			pq.emplace(w[v] - cnt[v], v);
		}
	}
	printf("ALIVE\n");
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}