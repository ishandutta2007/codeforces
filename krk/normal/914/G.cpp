#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1 << 17;
const int mod = 1000000007;

int Fib[Maxn];
int n;
int cnt[Maxn];
int A[Maxn];
int B[Maxn];

void Gen(int lvl, int a, int b)
{
	if (lvl >= 17) A[a | b] = (ll(A[a | b]) + ll(cnt[a]) * cnt[b]) % mod;
	else {
		Gen(lvl + 1, a, b);
		Gen(lvl + 1, (a | 1 << lvl), b);
		Gen(lvl + 1, a, (b | 1 << lvl));
	}
}

int Inv(int a)
{
	int res = 1;
	int p = mod - 2;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

void applyXor(int P[], bool inv)
{
	for (int len = 1; 2 * len <= Maxn; len <<= 1)
		for (int i = 0; i < Maxn; i += 2 * len)
			for (int j = 0; j < len; j++) {
				int u = P[i + j];
				int v = P[i + len + j];
				P[i + j] = (u + v) % mod;
				P[i + len + j] = (u - v + mod) % mod;
			}
	if (inv) {
		int val = Inv(Maxn);
		for (int i = 0; i < Maxn; i++)
			P[i] = ll(P[i]) * val % mod;
	}
}

void multiplyXor()
{
	for (int i = 0; i < Maxn; i++)
		B[i] = cnt[i];
	applyXor(B, false);
	for (int i = 0; i < Maxn; i++)
		B[i] = ll(B[i]) * B[i] % mod;
	applyXor(B, true);
}


void applyAnd(int P[], bool inv)
{
	for (int len = 1; 2 * len <= Maxn; len <<= 1)
		for (int i = 0; i < Maxn; i += 2 * len)
			for (int j = 0; j < len; j++) {
				int u = P[i + j];
				int v = P[i + len + j];
				if (!inv) {
					P[i + j] = v;
					P[i + len + j] = (u + v) % mod;
				} else {
					P[i + j] = (v - u + mod) % mod;
					P[i + len + j] = u;
				}
			}
}

void multiplyAnd(int A[], int B[])
{
	applyAnd(A, false); applyAnd(B, false);
	for (int i = 0; i < Maxn; i++)
		A[i] = ll(A[i]) * B[i] % mod;
	applyAnd(A, true);
}

int main()
{
	Fib[0] = 0; Fib[1] = 1;
	for (int i = 2; i < Maxn; i++)
		Fib[i] = (Fib[i - 1] + Fib[i - 2]) % mod;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		cnt[a]++;
	}
	Gen(0, 0, 0);
	multiplyXor();
	for (int i = 0; i < Maxn; i++) {
		cnt[i] = ll(cnt[i]) * Fib[i] % mod;
		A[i] = ll(A[i]) * Fib[i] % mod;
		B[i] = ll(B[i]) * Fib[i] % mod;
	}
	multiplyAnd(cnt, A);
	multiplyAnd(cnt, B);
	int res = 0;
	for (int i = 0; i < 17; i++)
		res = (res + cnt[1 << i]) % mod;
	printf("%d\n", res);
	return 0;
}