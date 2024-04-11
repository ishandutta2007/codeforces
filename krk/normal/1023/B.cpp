#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;

int main()
{
	cin >> n >> k;
	ll lef = max(1ll, k - n);
	ll rig = (k - 1) / 2;
	ll res = max(0ll, rig - lef + 1);
	printf("%I64d\n", res);
	return 0;
}