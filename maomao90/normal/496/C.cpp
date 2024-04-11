#include <bits/stdc++.h>

using namespace std;

int n, m;
char table[105][105];
bool done[105];
int ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf(" %s", table[i]);
	for (int i = 0; i < m; i++) {
		bool ordered = true;
		for (int j = 1; j < n; j++) {
            if (done[j]) continue;
            // printf("%d %d\n", j, i);
			if (table[j][i] < table[j - 1][i]) {
				ordered = false;
				break;
			}
		}
		if (!ordered) ans++;
		else {
            for (int j = 1; j < n; j++) {
                if (done[j]) continue;
                if (table[j][i] != table[j - 1][i]) {
                    done[j] = true;
                }
            }
		}
	}
	printf("%d\n", ans);
	return 0;
}