#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

char s[N];

int n;

bool st[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);	
		for (int i = 1; i <= n; i++) st[i] = false;
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			if (s[i] == s[i - 1]) {
				if (!st[i - 1]) {
					st[i] = true;
					ans++;
				}
			}
			if (i > 2 && s[i] == s[i - 2]) {
				if (!st[i - 2]) {
					st[i] = true;
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}