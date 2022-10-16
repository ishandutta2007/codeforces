#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 105;

char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		int c = 0, t = 0;
		for (int i = 1; i <= n; i++) {
			t += s[i] - '0';
			if (s[i] == '0') c = i;
		}
		bool o = false;
		for (int i = 1; i <= n; i++) {
			if (i != c && (s[i] - '0') % 2 == 0) {
				o = 1;
			}
		}
		if (o && c && (t % 3 == 0)) puts("red");
		else puts("cyan");
	}
	return 0;
}