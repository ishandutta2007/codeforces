#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)


int n;
char s[1231231];
LL cnt[1231231], cc[1231231];

int main() {
	scanf("%s", s);
	n = (int)strlen(s);
	for (int i = 0 ;i < n; i++) {
		if (s[i] == 'v' && s[i + 1] == 'v') cnt[i] = cnt[i - 1] + 1;
		else cnt[i] = cnt[i - 1];
	}
	for (int i = n - 1 ; ~i; i--) {
		if (s[i] == 'v' && s[i + 1] == 'v') cc[i] = cc[i + 1] + 1;
		else cc[i] = cc[i + 1];
	}
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			ans += cnt[i] * cc[i];
		}
	}
	printf("%lld\n", ans);
	
}