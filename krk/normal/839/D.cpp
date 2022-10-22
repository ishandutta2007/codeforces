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
const int Maxn = 1000005;

int pw[Maxn];
int delt[Maxn];
int n;
int cnt[Maxn];
int res;

int main()
{
	pw[0] = 1;
	for (int i = 1; i < Maxn; i++)
		pw[i] = 2 * pw[i - 1] % mod;
	for (int i = 2; i < Maxn; i++) {
		delt[i] = (delt[i] + i) % mod;
		for (int j = i + i; j < Maxn; j += i)
			delt[j] = (delt[j] - delt[i] + mod) % mod;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		cnt[a]++;
	}
	for (int i = Maxn - 1; i >= 2; i--) if (delt[i] != 0) {
		int tot = 0;
		for (int j = i; j < Maxn; j += i)
			tot += cnt[j];
		if (tot > 0)
			res = (res + ll(tot) * pw[tot - 1] % mod * delt[i]) % mod;
	}
	printf("%d\n", res);
	return 0;
}