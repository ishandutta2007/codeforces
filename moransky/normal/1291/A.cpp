#include <cstdio>
#include <iostream>
using namespace std;
const int N = 3005;
int n;
char s[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, s);
		int t = -1;
		for (int i = n - 1; i >= 0; i--) {
			if ((s[i] - '0') & 1) { t = i; break; }
		}
		if (t == -1) {
			puts("-1");
			continue;
		}
		int c = -1;
		for (int i = t - 1; i >= 0; i--) {
			if ((s[i] - '0') & 1) { c = i; break;}
		}
		if (c == -1) {
			puts("-1");
		} else printf("%c%c\n", s[c], s[t]);
	}
	return 0;
}