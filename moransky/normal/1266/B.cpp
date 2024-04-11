#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

LL x;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%lld", &x);
		if (x < 15) {
			puts("NO");
			continue;
		}
		LL b = x % 14;
		while (b + 14 <= 20 && b + 14 <= x) b += 14;
		if (b >= 15 && b <= 20) puts("YES");
		else puts("NO");		
	}
	return 0;
}