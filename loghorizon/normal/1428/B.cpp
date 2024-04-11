#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 300005;

int n;
char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, s + 1);
		int c1 = 0, c2 = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '>') c1++;
			else if (s[i] == '<') c2++;
			int nx = i == 1 ? n : i - 1;
			if (s[i] == '-' || s[nx] == '-') cnt++;
		}
		if (!c1 || !c2) printf("%d\n", n);
		else printf("%d\n", cnt);
	}	
	return 0;
}