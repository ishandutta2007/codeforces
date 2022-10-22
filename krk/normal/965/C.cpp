#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
ll m;
int d;
ll res = 0;

int main()
{
	scanf("%I64d %I64d %I64d %d", &n, &k, &m, &d);
	for (int i = 1; i <= d && 1 + ll(i - 1) * k <= n; i++) {
		ll tims = 1 + ll(i - 1) * k;
		ll X = min(m, n / tims);
		ll lft = n - (X - 1);
		bool ok = ll(i) * k <= lft / X && ll(i) * k * X == lft || ll(i) * k > lft / X;
		if (ok) res = max(res, ll(i) * X);
	}
	cout << res << endl;
	return 0;
}