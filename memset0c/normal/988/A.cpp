#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, r::c = std::getchar(), r::m = 1; \
	while (!isnum(r::c) && r::c != '-') r::c = getchar(); \
	if (r::c == '-') r::m = -1, r::c = getchar(); \
	while (isnum(r::c)) x = x * 10 + r::c - '0', r::c = getchar(); \
	x *= r::m; \
} while(0)
using namespace std;
namespace r {
	char c;
	int m;
}

const int maxn = 110;
int n, m, a[maxn], b[maxn], c[maxn];

int main() {
	
	read(n); read(m);
	for (int i = 1; i <= n; i++)
		 read(a[i]);
		 
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!b[a[i]]) {
			c[++cnt] = i;
			b[a[i]] = 1;
			if (cnt == m) break;
		}
	if (cnt == m) {
		printf("YES\n");
		for (int i = 1; i <= m; i++)
			printf("%d ", c[i]);
//		puts("");
	} else {
		printf("NO");
	}
	
	return 0;
}