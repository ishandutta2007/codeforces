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

int n;
int a, b;

bool Root(ll x, ll &res)
{
	ll lef = 1, rig = x;
	res = 1;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		if (mid <= x / mid / mid) { res = mid; lef = mid + 1; }
		else rig = mid - 1;
	}
	return res * res * res == x;
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &a, &b);
		ll got = ll(a) * b, rt;
		if (Root(got, rt))
			if (a % rt == 0 && b % rt == 0) {
				ll lft = ll(a / rt) * ll(b / rt);
				if (lft == rt) printf("Yes\n");
				else printf("No\n");
			} else printf("No\n");
		else printf("No\n");
	}
	return 0;
}