/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef long long LL;
typedef long double D;
int n, len;
char s[100];

LL convert() {
	LL ret = 0;
	for (int i = 1; i <= len; i++) {
		ret = ret * n + s[i] - '0';
	}
	return ret;
}

LL f[65];

LL cut(int l, int r) {
	l++;
	if (l != r && s[l] == '0') return n;
	LL ret = 0;
	for (int i = l; i <= r; i++) {
		ret = ret * 10 + s[i] - '0';
		if (ret >= n) return  ret;
	}
	return ret;
}

int main() {
	scanf("%d%s", &n, s + 1);
	len = (int) strlen(s + 1);
	if (n <= 10) cout << convert();
	else if (s[1] == 0) puts("0");
	else {
		memset(f, 0x3f, sizeof(f));
		f[0] = 0;
		for (int i = 1; i <= len; i++) {
			for (int j = i - 1; j > -1; j--) {
				LL part = cut(j, i);
				if (part >= n) continue;
				if (D(f[j]) * D(n) > D(f[64])) continue;
				f[i] = min(f[i], f[j] * n + part);
			}
		}
		printf("%lld\n", f[len]);
	}
	return 0;
}