#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int ma = 0, id = 0;
		int f = 0, last = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			if (last != x && i > 1) f = 1;
			if (x > ma) {
				ma = x, id = i;
			}
			if (x != ma) {
				if (last == ma) id = i - 1;
			}
			last = x;
		}
		if (f) printf("%d\n", id);
		else puts("-1");
	}


}