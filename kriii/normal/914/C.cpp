#include <stdio.h>

char N[1010];
int bc[1024],go[1024];

const long long mod = 1000000007;
long long comb[1010][1010];

int main()
{
	scanf("%s", N);
	for (int i = 1; i < 1024; i++) {
		bc[i] = bc[i - (i&(-i))] + 1;
	}

	for (int i = 2; i < 1024; i++) go[i] = go[bc[i]] + 1;

	int k; scanf("%d", &k);
	if (k == 0) {
		puts("1");
		return 0;
	}
	int l = 0;
	int c = 0;
	while (N[l]) {
		if (N[l] == '1') c++;
		l++;
	}
	for (int i = 0; i <= l; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
	}

	long long ans = 0;
	if (go[c] + 1 == k) ans = 1;

	c = 0;
	for (int i = 0; i < l; i++) if (N[i] == '1'){
		for (int j = 0; j <= l - i - 1; j++) if (go[c + j] + 1 == k) {
			long long now = comb[l - i - 1][j];
			ans = (ans + now) % mod;
		}
		c++;
	}
	if (k == 1) ans = (ans + mod - 2) % mod;
	printf("%lld\n", ans);

	return 0;
}