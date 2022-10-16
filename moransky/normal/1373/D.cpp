#include <cstdio>
#include <iostream>
using namespace std;
 
typedef long long LL;
 
const int N = 200005;
 
int n, a[N];
 
LL ans;
 
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		LL tot = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		for (int i = 0; i < n; i += 2) tot += a[i];
		LL s = 0; ans = tot;
		for (int i = 2; i < n; i += 2) {
			s = max(0ll, s + a[i - 1] - a[i]);
			ans = max(ans, tot + s);
		}
		s = 0;
		for (int i = 1; i < n; i += 2) {
			s = max(0ll, s - a[i - 1] + a[i]);
			ans = max(ans, tot + s);
		}
		printf("%lld\n", ans);
	}
	return 0;
}