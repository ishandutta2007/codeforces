#include <bits/stdc++.h>
using namespace std;

int t;
char str[200005];
int n;
int cnt1, cnt2;
int ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(str, 0, sizeof str);
		cnt1 = cnt2 = 0;
		ans = 0;
		scanf(" %s", str);
		n = strlen(str);
		for (int i = 0; i < n; i++) {
			if (str[i] == '(') cnt1++;
			else if (str[i] == '[') cnt2++;
			else if (str[i] == ')') {
				if (cnt1 > 0) {
					cnt1--;
					ans++;
				}
			} else {
				if (cnt2 > 0) {
					cnt2--;
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}