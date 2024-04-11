#include <bits/stdc++.h>
using namespace std;

int t;
int k;
char str[105];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);
		memset(str, 0, sizeof str);
		scanf(" %s", str);
		bool isAngry = false;
		int cnt = 0;
		int ans = 0;
		for (int i = 0; i < k; i++) {
			if (isAngry && str[i] == 'P') {
				cnt++;
			}
			ans = max(ans, cnt);
			if (str[i] == 'A') {
				isAngry = true;
				cnt = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}