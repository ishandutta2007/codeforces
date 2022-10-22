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

const int mod = 1000003;
const int Maxn = 105;

int C, W, H;
int Hp;
int dp[Maxn], pnt;
int cur;

int main()
{
	scanf("%d %d %d", &C, &W, &H);
	Hp = 1;
	for (int i = 0; i < W + 1; i++)
		Hp = ll(Hp) * H % mod;
	cur = -1; dp[pnt] = 1; dp[(pnt + 1) % Maxn] = (mod - H) % mod;
	int has = 0;
	while (cur < C) {
		has = (ll(has) * H + ll(dp[pnt])) % mod; dp[pnt] = 0;
		dp[(pnt + 1) % Maxn] = (dp[(pnt + 1) % Maxn] + has) % mod;
		dp[(pnt + W + 2) % Maxn] = (dp[(pnt + W + 2) % Maxn] - ll(has) * Hp % mod + mod) % mod;
		cur++; pnt = (pnt + 1) % Maxn;
	}
	has = (ll(has) * H + ll(dp[pnt])) % mod;
	printf("%d\n", has);
	return 0;
}