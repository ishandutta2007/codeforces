#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000000;
const int Maxm = 1 << 6;
const int mod = 1000000007;

int pw2[Maxn + 1];
int pw10[7];
int bts[Maxm];
int n;
int has[Maxn], sum[Maxn];
int sqsum[Maxn], mulsum[Maxn];
int res[Maxn];
ll tres;

int Get(int x, int d) { return x / pw10[d] % 10; }

void Solve1(int i, int d, int u, int j)
{
	if (d >= 6) {
		if (j) {
			if (bts[j] == 1) {
				has[i] = (has[i] + has[u]) % mod;
				mulsum[i] = (mulsum[i] + mulsum[u]) % mod;
				mulsum[i] = (mulsum[i] + 2ll * ll(sum[i]) % mod * sum[u]) % mod;
				sum[i] = (sum[i] + sum[u]) % mod;
				sqsum[i] = (sqsum[i] + sqsum[u]) % mod;
			} else {
				has[i] = (has[i] - has[u] + mod) % mod;
				sum[i] = (sum[i] - sum[u] + mod) % mod;
				sqsum[i] = (sqsum[i] - sqsum[u] + mod) % mod;
				mulsum[i] = (mulsum[i] - mulsum[u] + mod) % mod;
				mulsum[i] = (mulsum[i] - 2ll * ll(sum[i]) % mod * sum[u] % mod + mod) % mod;
			}
		}
	}
	else {
		Solve1(i, d + 1, u, j);
		if (Get(i, d) < 9) Solve1(i, d + 1, u + pw10[d], (j | 1 << d));
	}
}

void Solve2(int i, int d, int u, int j)
{
	if (d >= 6) {
		if (j) {
			if (bts[j] == 1) res[i] = (res[i] - res[u] + mod) % mod;
			else res[i] = (res[i] + res[u]) % mod;
		}
	}
	else {
		Solve2(i, d + 1, u, j);
		if (Get(i, d) < 9) Solve2(i, d + 1, u + pw10[d], (j | 1 << d));
	}
}

int main()
{
	pw2[0] = pw10[0] = 1;
	for (int i = 1; i <= Maxn; i++)
		pw2[i] = 2 * pw2[i - 1] % mod;
	for (int i = 1; i <= 6; i++)
		pw10[i] = 10ll * ll(pw10[i - 1]) % mod;
	for (int i = 0; i < Maxm; i++)
		bts[i] = __builtin_popcount(i) % 2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		has[a]++;
	}
	for (int i = Maxn - 1; i >= 0; i--) {
		sum[i] = ll(has[i]) * i % mod;
		sqsum[i] = ll(has[i]) * i % mod * i % mod;
		mulsum[i] = ll(has[i]) * (has[i] - 1) % mod * i % mod * i % mod;
		Solve1(i, 0, i, 0);
		if (has[i] > 0) res[i] = ll(sqsum[i]) * pw2[has[i] - 1] % mod;
		if (has[i] > 1) res[i] = (res[i] + ll(mulsum[i]) * pw2[has[i] - 2]) % mod;
	}
	for (int i = 0; i < Maxn; i++) {
		Solve2(i, 0, i, 0);
		tres ^= (ll(i) * res[i]);
	}
	cout << tres << endl;
	return 0;
}