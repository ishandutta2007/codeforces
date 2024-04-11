#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define i64 long long int

struct modular_arithmetic {
	int mod;

	modular_arithmetic() {
		mod = 998244353;
	}
	//No specific settings.
	int add(int x, int y) { return (x += y)<mod ? x : x - mod; }
	int sub(int x, int y) { return (x -= y) >= 0 ? x : x + mod; }
	int mul(int x, int y) { return (int)((long long int)x*y%mod); }
	int pw(int base, int p) {
		int res = 1, mu = base % mod;
		for (;p>0;p /= 2) {
			if (p & 1) res = mul(res, mu);
			mu = mul(mu, mu);
		}
		return res;
	}
	int rev(int x) { return pw(x, mod - 2); }
};
modular_arithmetic ma;

int dp[555][555], n, k;
void addto(int&x, int y) { x = ma.add(x, y); }
int main() {
	scanf("%d%d", &n, &k);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)for (int j = 0; j <= i; j++)for (int k = 1; i + k <= n; k++)
		addto(dp[i + k][max(j, k)], dp[i][j]);
	int res = 0;
	for (int t = 1; t <= n; t++)for (int t2 = 1; t2 <= n && t * t2 < k; t2++)
		addto(res, ma.mul(dp[n][t], dp[n][t2]));
	printf("%d\n", ma.mul(2, res));
	return 0;
}