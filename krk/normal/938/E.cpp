#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1000005;

int res;
int n;
int a[Maxn];

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); a[i] = -a[i];
	}
	sort(a, a + n);
	for (int i = 0, j; i < n; i = j) {
		j = i;
		while (j < n && a[i] == a[j]) j++;
		if (i > 0)
			res = (res + ll(j - i) * Inv(j) % mod * (-a[i])) % mod;
	}
	for (int i = 2; i <= n; i++)
		res = ll(res) * i % mod;
	printf("%d\n", res);
	return 0;
}