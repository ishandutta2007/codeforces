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
const int Maxn = 300005;

int pw2[Maxn];
int n;
int a[Maxn];
int res;

int main()
{
	pw2[0] = 1;
	for (int i = 1; i < Maxn; i++)
		pw2[i] = 2ll * pw2[i - 1] % mod;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		res = (res + ll(pw2[i]) * a[i]) % mod;
		res = (res - ll(pw2[n - 1 - i]) * a[i] % mod + mod) % mod;
	}
	printf("%d\n", res);
	return 0;
}