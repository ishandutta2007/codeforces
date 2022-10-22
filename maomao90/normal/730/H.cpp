#include <bits/stdc++.h>

using namespace std;

int n, m;
char files[105][105];
int a[105];
bool deleted[105];
int len;
char ans[105];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf(" %s", files[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
		deleted[a[i]] = true;
	}
	len = strlen(files[a[0]]);
	for (int i = 1; i < m; i++) {
		if (len != strlen(files[a[i]])) {
			printf("No\n");
			return 0;
		}
	}
	for (int i = 0; i < len; i++) {
		bool isSame = true;
		char cur = files[a[0]][i];
		for (int j = 1; j < m; j++) {
			if (cur != files[a[j]][i]) {
				isSame = false;
				break;
			}
		}
		if (isSame) ans[i] = cur;
		else ans[i] = '?';
	}
	for (int i = 1; i <= n; i++) {
		if (!deleted[i]) {
			if (strlen(files[i]) != len) continue;
			bool match = true;
			for (int j = 0; j < len; j++) {
				if (ans[j] == '?') continue;
				if (ans[j] != files[i][j]) {
					match = false;
					break;
				}
			}
			if (match) {
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	printf("%s\n", ans);
	return 0;
}