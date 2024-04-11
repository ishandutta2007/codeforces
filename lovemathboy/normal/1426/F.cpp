#include <bits/stdc++.h>
using namespace std;

char s[200010];
long long mod = 1000000007;

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	long long a = 1;
	long long b = 0;
	long long c = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			b += a;
			b %= mod;
		}
		if (s[i] == 'b') {
			c += b;
			c %= mod;
		}
		if (s[i] == 'c') {
			ans += c;
			ans %= mod;
		}
		if (s[i] == '?') {
			long long oa = a, ob = b, oc = c;
			a *= 3;
			b *= 3;
			c *= 3;
			ans *= 3;
			b += oa;
			c += ob;
			ans += oc;
			a %= mod;
			b %= mod;
			c %= mod;
			ans %= mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}