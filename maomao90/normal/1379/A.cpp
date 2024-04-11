#include <bits/stdc++.h>
using namespace std;

#define STRSIZE 7

int t;
int n;
char str[55];
char target[] = "abacaba";

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(str, 0, sizeof str);
		scanf(" %s", str);
		bool found = false;
		for (int i = 0; i < n - STRSIZE + 1; i++) {
			bool can = true;
			for (int j = 0; j < STRSIZE; j++) {
				if (str[i + j] != '?' && str[i + j] != target[j]) {
					can = false;
					break;
				}
			}
			if (!can) continue;
			char temp[n + 5];
			strcpy(temp, str);
			for (int j = 0; j < STRSIZE; j++) {
				temp[i + j] = target[j];
			}
			for (int j = 0; j < n - STRSIZE + 1; j++) {
				if (i == j) continue;
				bool can1 = true;
				for (int k = 0; k < STRSIZE; k++) {
					if (temp[j + k] != target[k]) {
						can1 = false;
						break;
					}
				}
				if (can1) {
					can = false;
					break;
				}
			}
			if (!can) continue;
			found = true;
			for (int j = 0; j < STRSIZE; j++) {
				str[i + j] = target[j];
			}
		}
		if (found) {
			printf("Yes\n");
			for (int i = 0; i < n; i++) {
				if (str[i] == '?') str[i] = 'z';
				printf("%c", str[i]);
			}
			printf("\n");
		} else printf("No\n");
	}
	return 0;
}