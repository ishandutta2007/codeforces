#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int n, x, pos;

int main()
{
	scanf("%d %d %d", &n, &x, &pos);
	int small = 0, large = 0;
	int l = 0, r = n;
	while (l < r) {
		int m = l + r >> 1;
		if (m <= pos) { small++; l = m + 1; }
		else { large++; r = m; }
	}
	small--;
	int has1 = x - 1;
	int has2 = n - x;
	if (small > has1 || large > has2) { printf("0\n"); return 0; }
	int res = 1;
	for (int i = 0; i < small; i++) {
		res = ll(res) * has1 % mod;
		has1--;
	}
	for (int i = 0; i < large; i++) {
		res = ll(res) * has2 % mod;
		has2--;
	}
	int lft = has1 + has2;
	while (lft > 0) {
		res = ll(res) * lft % mod;
		lft--;
	}
	printf("%d\n", res);
    return 0;
}