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

const int Maxn = 105;
const int mod = 1000000007;

int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	int res = ll(2) * (n - m + 1) % mod;
	for (int i = 0; i < m - 1; i++) {
		res = ll(res) * 2ll % mod * (n + 1) % mod;
	}
	printf("%d\n", res);
	return 0;
}