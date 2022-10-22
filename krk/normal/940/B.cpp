#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;

int n, k;
ll A, B;
ll res = Inf;

int main()
{
	cin >> n >> k;
	cin >> A >> B;
	if (k == 1) { cout << ll(A) * (n - 1) << endl; return 0; }
	ll cur = 0;
	while (n > 1) {
		res = min(res, cur + ll(n - 1) * A);
		if (n % k) { cur += ll(n % k) * A; n -= n % k; }
		if (n != 0) {
			n /= k; cur += B;
		}
	}
	res = min(res, cur);
	cout << res << endl;
	return 0;
}