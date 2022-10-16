#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
 
const int N = 1000005;
 
char s[N];
 
int n, v[N];
 
LL ans;
 
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int cnt = 0, d = 2e9;
		ans = 0;
		for (int i = 0; i <= n; i++) v[i] = 2e9;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '+') cnt++;
			else cnt--;
			if (cnt < 0) v[(-cnt) - 1] = min(v[- cnt - 1], i); 
			d = min(d, cnt);
		}
		for (int i = n - 1; ~i; i--) v[i] = min(v[i], v[i + 1]);
		if (d >= 0) printf("%d\n", n);
		else {
			d = -d - 1;
			ans = n;
			for (int i = 0; i <= d; i++) {
				ans += v[i];
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}