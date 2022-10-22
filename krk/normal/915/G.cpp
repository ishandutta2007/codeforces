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

const int Maxm = 2000005;
const int mod = 1000000007;

bool prime[Maxm];
int mu[Maxm];
int delt[Maxm];
int pw[Maxm];
int n, k;

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int main()
{
	fill(prime + 2, prime + Maxm, true);
	fill(mu + 1, mu + Maxm, 1);
	for (int i = 2; i < Maxm; i++) if (prime[i])
		for (int j = i; j < Maxm; j += i) {
			if (j > i) prime[j] = false;
			if (j / i % i == 0) mu[j] = 0;
			else mu[j] = -mu[j];
		}
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++)
		pw[i] = toPower(i, n);
	for (int i = k; i > 0; i--) if (mu[i] != 0)
		for (int j = i; j <= k; j += i) {
			int to = min(k + 1, j + i);
			int my = pw[j / i];
			if (mu[i] < 0) my = (mod - my) % mod;
			delt[j] = (delt[j] + my) % mod;
			delt[to] = (delt[to] - my + mod) % mod;
		}
	int res = 0;
	int cur = 0;
	for (int i = 1; i <= k; i++) {
		cur = (cur + delt[i]) % mod;
		res = (res + (cur ^ i)) % mod;
	}
	printf("%d\n", res);
	return 0;
}