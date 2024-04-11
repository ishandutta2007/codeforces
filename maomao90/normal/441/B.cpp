#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int n, v;
deque <int> pickable[3010];
int rem[3010];
int ans;

int main() {
	scanf("%d%d", &n, &v);
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d%d", &a, &b);
		pickable[a].push_back(i);
		rem[i] = b;
	}
	for (int i = 3005; i > 0; i--) {
        for (int j : pickable[i]) {
            pickable[i + 1].push_front(j);
        }
	}
	for (int i = 1; i <= 3005; i++) {
		int curRem = v;
		for (int j : pickable[i]) {
            //printf("Day %d: %d left %d\n", i, j, rem[j]);
			if (curRem <= 0) break;
			int deduct = min(curRem, rem[j]);
			rem[j] -= deduct;
			curRem -= deduct;
			ans += deduct;
		}
	}
	printf("%d\n", ans);
	return 0;
}