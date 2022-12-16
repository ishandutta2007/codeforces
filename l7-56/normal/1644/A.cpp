#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

void work() {
	char s[10];
	scanf("%s", s);
	for (int i = 0, r = 0, g = 0, b = 0; i < 6; ++i) {
		switch (s[i]) {
			case 'R': {
				if (!r) return printf("NO\n"), void();
				break;
			}
			case 'G': {
				if (!g) return printf("NO\n"), void();
				break;
			}
			case 'B': {
				if (!b) return printf("NO\n"), void();
				break;
			}
			case 'r': r = 1; break;
			case 'g': g = 1; break;
			case 'b': b = 1; break;
			default : break;
		}
	}
	printf("YES\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}