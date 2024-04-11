#include <bits/stdc++.h>
using namespace std;

int tc;
int n;
char s[100050];

int main() {
	scanf("%d", &tc);
	
	while (tc--) {
		scanf("%d", &n);
		scanf("%s", s);
		int prev = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1' && prev == 2) {
				printf("0");
				prev = 1;
			}
			else if (s[i] == '1') {
				printf("1");
				prev = 2;
			}
			else if (s[i] == '0' && prev == 1) {
				printf("0");
				prev = 0;
			}
			else {
				printf("1");
				prev = 1;
			}
		}
		printf("\n");
	}
	return 0;
}