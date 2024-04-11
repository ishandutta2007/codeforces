#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int LIMN = 100500;
const int LIMA = 10000;
const int LIM = 1 << 14;
const int INF = 1e+9 + 7;

ll cnt[LIM];

void solve()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		++cnt[a];
	}
	ll res = 0;
	if (k == 0)
		for (int i = 0; i <= LIMA; ++i)
			res += cnt[i] * (cnt[i] - 1);
	for (int mask = 1; mask < LIM; ++mask)
	{
		int bits = 0;
		for (int i = mask; i; i >>= 1)
		{
			bits += i & 1;
		}
		if (bits == k)
		{
			for (int i = 0; i <= LIMA; ++i)
				res += cnt[i] * cnt[i ^ mask];
		}
	}
	printf("%lld", res / 2);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}