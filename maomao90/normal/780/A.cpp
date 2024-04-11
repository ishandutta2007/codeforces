#include <bits/stdc++.h>
using namespace std;

int n;
bool isThr[200005];
int ans, cnt;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		int x; scanf("%d", &x);
		if (isThr[x]) cnt--;
		else {
			isThr[x] = true;
			cnt++;
			ans = max(cnt, ans);
		}
	}
	printf("%d\n", ans);
	return 0;
}