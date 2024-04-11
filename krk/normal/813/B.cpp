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

vector <ll> V;
ll x, y, l, r;
ll res;

int main()
{
	cin >> x >> y >> l >> r;
	V.push_back(l - 1); V.push_back(r + 1);
	ll a = 1;
	while (true) {
		ll b = 1;
		while (true) {
			if (l <= a + b && a + b <= r)
				V.push_back(a + b);
			if (b > (r - a) / y) break;
			b *= y;
		}
		if (a > r / x) break;
		a *= x;
	}
	sort(V.begin(), V.end()); V.erase(unique(V.begin(), V.end()), V.end());
	for (int i = 0; i + 1 < V.size(); i++)
		res = max(res, V[i + 1] - V[i] - 1);
	printf("%I64d\n", res);
	return 0;
}