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

const int Maxm = 71;
const int Maxp = 11;
const int Maxn = 100005;
const int mod = 1000000007;

int pw2[Maxn];
int mx[Maxm];
int curid, id[Maxm];
int n;
int cur, dp[2][1 << Maxp];
int cnt[Maxm];

bool Prime(int x)
{
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

int main()
{
	for (int i = 2; i < Maxm; i++) if (mx[i] == 0) {
		if (mx[i] == 0 && i * 2 < Maxm) id[i] = curid++;
		for (int j = i; j < Maxm; j += i) mx[j] = i;
	}
	pw2[0] = 1;
	for (int i = 1; i < Maxn; i++)
		pw2[i] = 2ll * pw2[i - 1] % mod;
	dp[0][0] = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (mx[a] == a && a * 2 >= Maxm) { cnt[a]++; continue; }
		int mask = 0;
		while (a > 1) {
			int dv = mx[a];
			mask ^= 1 << id[dv];
			a /= dv;
		}
		for (int j = 0; j < 1 << Maxp; j++) if (dp[cur][j]) {
			int val = dp[cur][j];
			dp[!cur][j] = (dp[!cur][j] + val) % mod;
			dp[!cur][j ^ mask] = (dp[!cur][j ^ mask] + val) % mod;
			dp[cur][j] = 0;
		}
		cur = !cur;
	}
	int res = dp[cur][0];
	for (int i = 2; i < Maxm; i++) if (i * 2 >= Maxm && cnt[i] > 0)
		res = ll(res) * pw2[cnt[i] - 1] % mod;
	res = (res - 1 + mod) % mod;
	printf("%d\n", res);
	return 0;
}