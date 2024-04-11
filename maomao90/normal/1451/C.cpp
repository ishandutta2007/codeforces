#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int t;
int n, k;
char a[MAXN], b[MAXN];
int cnta[30], cntb[30];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		scanf(" %s", a);
		scanf(" %s", b);
		memset(cnta, 0, sizeof cnta);
		memset(cntb, 0, sizeof cntb);
		for (int i = 0; i < n; i++) {
			cnta[a[i] - 'a']++;
			cntb[b[i] - 'a']++;
		}
		int rem = 0;
		bool pos = true;
		for (int i = 0; i < 26; i++) {
			rem += cnta[i];
			if (cntb[i] > rem || (rem - cntb[i]) % k != 0) {
				pos = false;
				break;
			}
			rem -= cntb[i];
		}
		if (pos) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}