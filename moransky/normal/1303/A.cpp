#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 105;
int n;
char s[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (s[i] == '1') cnt++;

		bool op = false;
		int tot = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') op = true, tot++;
			if (s[i] == '0' && op && tot < cnt) ans++;
		}
		printf("%d\n", ans);
	}
}