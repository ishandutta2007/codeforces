#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
int n,q,bel[maxn],sum[maxn];
char s[maxn];

int main() {
	scanf("%d%d%s", &n, &q, s + 1);
	s[0] = s[1];
	for (int i = 1; i <= n; ++i) {
		bel[i] = bel[i - 1] + (s[i] == s[i - 1]);
		if (s[i] == s[i - 1]) sum[bel[i]] = sum[bel[i] - 1] + (s[i] == '0' ? -1 : 1);
	}
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		l = bel[l], r = bel[r];
		printf("%d\n", (r - l + abs(sum[r] - sum[l])) / 2 + 1);
	}
	return 0;
}