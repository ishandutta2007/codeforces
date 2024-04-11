#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxb = 60;
const int Maxn = 1000005;

int T;
int n;
ll x[Maxn];
int ones[Maxb];

int main()
{
	scanf("%d", &T);
	while (T--) {
		fill(ones, ones + Maxb, 0);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%I64d", &x[i]);
			for (int j = 0; j < Maxb; j++)
				if (x[i] & 1ll << ll(j))
					ones[j]++;
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			ll add = 0;
			for (int j = 0; j < Maxb; j++)
				if (x[i] & 1ll << ll(j))
					add = (add + (1ll << ll(j)) % mod * ll(n)) % mod;
				else add = (add + (1ll << ll(j)) % mod * ll(ones[j])) % mod;
			for (int j = 0; j < Maxb; j++)
				if (x[i] & 1ll << ll(j))
					res = (res + (1ll << ll(j)) % mod * ll(ones[j]) % mod * add) % mod;
		}
		printf("%d\n", res);
	}
    return 0;
}