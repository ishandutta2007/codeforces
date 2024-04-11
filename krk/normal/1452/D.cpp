#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;

int n;
int inv2 = (mod + 1) / 2;
int sum[2];
int f[Maxn];

int main()
{
	scanf("%d", &n);
	f[0] = 1; sum[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = ll(sum[1 - i % 2]) * inv2 % mod;
		sum[i % 2] = (ll(sum[i % 2]) * ll(inv2) % mod * ll(inv2) + f[i]) % mod;
	}
	printf("%d\n", f[n]);
    return 0;
}