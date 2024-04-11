#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int n;
int a[200005];
set<ii> ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int curSum = 0;
		for (int j = i + 2; j < n; j++) {
			curSum += a[j - 1];
			if (curSum >= a[i] * 2) break;
			if ((a[i] ^ a[j]) == curSum) {
				ans.insert(ii(i, j));
			}
		}
		curSum = 0;
		for (int j = i - 2; j >= 0; j--) {
			curSum += a[j + 1];
			if (curSum > a[i] * 2) break;
			if ((a[i] ^ a[j]) == curSum) {
				ans.insert(ii(j, i));
			}
		}
	}
	printf("%d\n", (int) ans.size());
	return 0;
}