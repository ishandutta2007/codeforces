#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Maxd = 10;

int f[Maxn];
int cnt[Maxn][Maxd];
int q;
int l, r, k;

int Mult(int x)
{
	int res = 1;
	while (x) {
		if (x % 10)
			res *= x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	for (int i = 1; i < Maxn; i++) {
		if (i < 10) f[i] = i;
		else f[i] = f[Mult(i)];
		for (int j = 1; j < Maxd; j++)
			cnt[i][j] = cnt[i - 1][j];
		cnt[i][f[i]]++;
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d %d", &l, &r, &k);
		printf("%d\n", cnt[r][k] - cnt[l - 1][k]);
	}
	return 0;
}