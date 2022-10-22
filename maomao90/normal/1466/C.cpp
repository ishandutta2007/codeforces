#include <bits/stdc++.h>
using namespace std;

int t;
char str[100005];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(str, 0, sizeof str);
		scanf(" %s", &str);
		int n = strlen(str);
		int cnt = 0;
		if (str[1] == str[0]) {
			str[1] = '-';
			cnt++;
		}
		for (int i = 2; i < n; i++) {
			if (str[i] == str[i - 1] || str[i] == str[i - 2]) {
				str[i] = '-';
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}