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

int q;
int n;

ll Get(ll b)
{
	return b + min(b, (n - b) * (n - b - 1) / 2ll);
}

int main()
{
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		ll lef = 0, rig = n - 1;
		while (lef <= rig) {
			ll mid = lef + rig >> 1;
			if (ll(mid) <= ll(n - mid) * (n - mid - 1) / 2ll) lef = mid + 1;
			else rig = mid - 1;
		}
		lef--;
		ll res = 0;
		for (int i = 0; i <= 10 && lef + i < n; i++)
			res = max(res, Get(lef + i));
		printf("%I64d\n", res);
	}
	return 0; 
}