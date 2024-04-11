#include <bits/stdc++.h>
using namespace std;

int n, m;
bool can[105];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			int b; scanf("%d", &b);
			can[b] = true;
		}
	}
	bool correct = true;
	for (int i = 1; i <= m; i++) if (!can[i]) correct = false;
	if (correct) printf("YES\n");
	else printf("NO\n");
	return 0;
}