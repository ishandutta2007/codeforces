#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 20000005;

int vals[Maxm];
int T;
int c, d, x;

int gcd(int a, int b) { return a? gcd(b % a, a): b; }

int Solve(int g)
{
	int got = x / g + d;
	if (got % c) return 0;
	return vals[got / c];
}

int main()
{
	fill(vals, vals + Maxm, 1);
	for (int i = 2; i < Maxm; i++) if (vals[i] == 1)
		for (int j = i; j < Maxm; j += i)
			vals[j] *= 2;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &c, &d, &x);
		ll res = 0;
		for (int i = 1; i * i <= x; i++) if (x % i == 0) {
			res += Solve(i);
			if (i * i < x) res += Solve(x / i);
		}
		printf("%I64d\n", res);
	}
    return 0;
}