#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef tuple <int, int, int> iii;

int n, mx, reg;
int pw, damage;
iii pd[1005];
int cur, netdmg;
priority_queue<ii> pq;
vector <ii> ans;

int main() {
	scanf("%d%d%d", &n, &mx, &reg);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &pw, &damage);
		pd[i - 1] = iii(pw, damage, i);
	}
	sort(pd, pd + n, greater <iii> ());
	int ptr = 0;
	bool can = false;
	cur = mx;
	int i = 0;
	for (i = 0; i < 1000005; i++) {
		double percent = (double) cur * 100 / mx;
		int p, d, index; tie(p, d, index) = pd[ptr];
		while (p >= percent && ptr < n) {
			pq.emplace(d, index);
			tie(p, d, index) = pd[++ptr];
		}
		if (!pq.empty()) {
			netdmg += pq.top().first;
			ans.emplace_back(i, pq.top().second);
            pq.pop();
		}
		cur -= netdmg;
		cur = min(mx, cur + reg);
		if (cur <= 0) {
			can = true;
			break;
		}
	}
	if (can) {
		printf("YES\n");
		printf("%d %d\n", i + 1, ans.size());
		for (ii a : ans) {
			printf("%d %d\n", a.first, a.second);
		}
	} else {
		printf("NO\n");
	}
	return 0;
}