#include <bits/stdc++.h>
using namespace std;

int n;
int a[55555][5];
bool check(int x) {
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (a[x][j] < a[i][j]) cnt++;
		}
		if (cnt >= 3) tot ++;
	}
	return tot == n - 1;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 5; j++) {
				scanf("%d", a[i] + j);
			}
		}
		int ans = -1, cur = 1;
		for (int i = 2; i <= n; i++) {
			int cnt = 0;
			for (int j = 0; j < 5; j++) {
				cnt += a[cur][j] < a[i][j];
			}
			if (cnt < 3) {
				cur = i;
			}
		}
		printf("%d\n", check(cur) ? cur : -1);
	}
}