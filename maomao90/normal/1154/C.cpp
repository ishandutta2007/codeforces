#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1000000005

int order[] = {0, 1, 2, 0, 2, 1, 0};
int mxarr[3] = {3, 2, 2};
int arr[3], temparr[3];
int ans;

int main() {
	scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
	for (int i = 0; i < 7; i++) {
		temparr[0] = arr[0], temparr[1] = arr[1], temparr[2] = arr[2];
		int cur = 0;
		bool stop = false;
		for (int j = i; j < 7; j++) {
			// printf("%d: %d\n", j, temparr[order[j]]);
			if (--temparr[order[j]] < 0) {
				stop = true;
				ans = max(cur, ans);
				break;
			} else cur++;
		}
		if (stop) continue;
		int weeks = INF;
		for (int j = 0; j < 3; j++) weeks = min(weeks, temparr[j] / mxarr[j]);
		for (int j = 0; j < 3; j++) temparr[j] -= weeks * mxarr[j];
		cur += weeks * 7;
		for (int j = 0; j < 7; j++) {
			if (--temparr[order[j]] < 0) {
				break;
			} else cur++;
		}
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
	return 0;
}