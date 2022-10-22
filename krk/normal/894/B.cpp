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

const int mod = 1000000007;

ll n, m;
int k;

int toPower(int a, ll pw)
{
	int res = 1;
	while (pw) {
		if (pw & 1) res = ll(res) * a % mod;
		pw >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int main()
{
	scanf("%I64d %I64d %d", &n, &m, &k);
	if (k == -1 && (n + m) % 2 != 0) printf("0\n");
	else {
		int res = toPower(toPower(2, n - 1), m - 1);
		printf("%d\n", res);
	}
	return 0;
}