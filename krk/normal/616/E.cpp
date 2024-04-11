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

const int mod = 1000000007;

ll n, m;
int res;

int getSum(ll a, ll b)
{
	ll s1 = a + b, s2 = b - a + 1;
	if (s1 % 2 == 0) s1 /= 2;
	else s2 /= 2;
	return (s1 % mod) * (s2 % mod) % mod;
}

int main()
{
	cin >> n >> m;
	res = (n % mod) * (m % mod) % mod;
	ll cur = 1;
	while (cur <= m && cur <= n) {
		ll tims = n / cur;
		ll en = min(n / tims, m);
		ll got = ll(getSum(cur, en)) * (tims % mod) % mod;
		res = (res - got + mod) % mod;
		cur = en + 1;
	}
	printf("%d\n", res);
	return 0;
}