#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

#define in(a, b) (((a) >> (b)) & 1)
int a,b;
void work() {
	scanf("%d%d", &a, &b);
	int ans = b - a;
	for (int i = a; i < b; ++i) {
		int x = b;
		for (int bit = 30; bit >= 0; --bit)
			if (in(i, bit) && !in(b, bit)) {
				x = ((b >> bit) << bit);
				break;
			}
		ans = min(ans, i - a + (i | x) - b + 1);
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}