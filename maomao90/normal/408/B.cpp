#include <bits/stdc++.h>
using namespace std;

int cnta[30];
int cntb[30];
char a[1005], b[1005];
int ans;

int main() {
	scanf(" %s", &a);
	scanf(" %s", &b);
	for (int i = 0; i < strlen(a); i++) {
		cnta[a[i] - 'a']++;
	}
	for (int i = 0; i < strlen(b); i++) {
		cntb[b[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnta[i] == 0 && cntb[i] != 0) {
			printf("-1\n");
			return 0;
		}
		ans += min(cntb[i], cnta[i]);
	}
	if (ans == 0) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}