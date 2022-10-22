#include <cstdio>

using namespace std;

int t;
int n;
char s[100005];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", s);
		int l = n, r = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '0') {
				r = i;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				l = i;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if (i >= l && i < r) continue;
			printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}