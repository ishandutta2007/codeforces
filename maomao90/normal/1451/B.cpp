#include <bits/stdc++.h>
using namespace std;

int t;
int n, q;
char str[105];
bool preHas[2][105], postHas[2][105];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &q);
		scanf(" %s", str);
		memset(preHas, 0, sizeof preHas);
		memset(postHas, 0, sizeof postHas);
		for (int i = 0; i < n; i++) {
			if (str[i] == '0') preHas[0][i] = true;
			else preHas[1][i] = true;
			if (i != 0) {
				preHas[0][i] |= preHas[0][i - 1];
				preHas[1][i] |= preHas[1][i - 1];
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (str[i] == '0') postHas[0][i] = true;
			else postHas[1][i] = true;
			if (i != n - 1) {
				postHas[0][i] |= postHas[0][i + 1];
				postHas[1][i] |= postHas[1][i + 1];
			}
		}
		for (int i = 0; i < q; i++) {
			int l, r; scanf("%d%d", &l, &r);
			l--; r--;
			bool pos = false;
			if (l != 0) pos |= preHas[str[l] - '0'][l - 1];
			if (r != n - 1) pos |= postHas[str[r] - '0'][r + 1];
			if (pos) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}