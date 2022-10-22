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

ll n, m;

int main()
{
	cin >> n >> m;
	if (n <= m) printf("%I64d\n", n);
	else {
		ll lef = 1, rig = 2000000000ll;
		ll res = 0;
		while (lef <= rig) {
			ll mid = lef + rig >> 1ll;
			if (mid * (mid - 1) / 2 >= n - m) { res = mid; rig = mid - 1; }
			else lef = mid + 1;
		}
		res += m - 1;
		printf("%I64d\n", res);
	}
	return 0;
}