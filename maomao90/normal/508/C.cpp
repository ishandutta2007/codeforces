#include <bits/stdc++.h>

using namespace std;

int m, t, r;
int w[305];
queue <int> lighted;
int ans;

int main() {
	scanf("%d%d%d", &m, &t, &r);
	for (int i = 0; i < m; i++) scanf("%d", &w[i]);
	if (t < r) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < m; i++) {
		while (!lighted.empty() && w[i] - lighted.front() > t) {
            //printf("Delete: %d %d\n", lighted.front(), w[i]);
            lighted.pop();
		}
		int sze = lighted.size();
		for (int j = r - sze; j > 0; j--) {
            //printf("Add: %d %d\n", w[i] - j, w[i]);
			lighted.push(w[i] - j);
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}