#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000009;
const int Maxk = 100005;

int n, a, b, k;
char str[Maxk];

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

void Sum(int a, int k, int &sum, int &pw)
{
	if (k == 0) { sum = 0; pw = 1; }
	else {
		int tsum, tpw; Sum(a, k / 2, tsum, tpw);
		sum = ll(tsum) * (1 + tpw) % mod;
		pw = ll(tpw) * tpw % mod;
		if (k % 2) {
			sum = (sum + pw) % mod;
			pw = ll(pw) * a % mod;
		}
	}
}

int main()
{
	scanf("%d %d %d %d", &n, &b, &a, &k);
	scanf("%s", str);
	int mult = ll(toPower(a, k)) * Inv(toPower(b, k)) % mod;
	int res = 0;
	for (int i = 0; i < k && i <= n; i++) {
		int cnt = (n - i) / k + 1;
		int sum, pw; Sum(mult, cnt, sum, pw);
		sum = ll(sum) * toPower(a, i) % mod * toPower(b, n - i) % mod;
		if (str[i] == '-') res = (res - sum + mod) % mod;
		else res = (res + sum) % mod;
	}
	printf("%d\n", res);
	return 0;
}