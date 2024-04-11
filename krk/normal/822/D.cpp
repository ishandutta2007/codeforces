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

const int Maxn = 5000005;
const int mod = 1000000007;
const ll Inf = 9000000000000000000ll;

int t, l, r;
ll dp[Maxn];

int main()
{
	cin >> t >> l >> r;
	fill(dp, dp + Maxn, Inf);
	dp[1] = 0;
	for (int i = 1; i < Maxn; i++)
		for (int j = i + i, tims = 1; j < Maxn; j += i, tims++)
			dp[j] = min(dp[j], dp[i] + ll(j) * tims / 2);
	int sum = 0;
	for (int i = r; i >= l; i--)
		sum = (ll(sum) * t + dp[i]) % mod;
	printf("%d\n", sum);
	return 0;
}