#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 200005;
int n, a[N];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		bool ok = false;
		int l, r;
		for (int i = 1; i < n; i++) {
			if(abs(a[i + 1] - a[i]) >= 2) {
				ok = true;
				l = i, r = i + 1;
				break;
			}
		}
		if(ok) {
			puts("YES");
			printf("%d %d\n", l, r);
		} else puts("NO");
	}
	return 0;

}