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
typedef pair <bool, int> bint;

const ll Inf = 1000000000000ll;
const int Maxn = 105;

int n;
ll k;
int a[Maxn];
int mx;

bool Check(ll x)
{
	ll res = 0;
	for (int i = 0; i < n && res <= k; i++)
		if (a[i] % x) res += x - a[i] % x;
	return res <= k;
}

bint Solve(int x)
{
	int nxt = mx;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % x) res += x - a[i] % x;
		if (x <= a[i])
			nxt = min(nxt, a[i] / (a[i] / x));
	}
	bint ans; ans.first = res <= k; ans.second = nxt;
	return ans;
}

int main()
{
	scanf("%d %I64d", &n, &k);
	mx = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	ll cur = 1;
	ll lst1, lst2;
	while (cur <= mx) {
		bint got = Solve(cur);
		if (got.first) lst1 = cur, lst2 = got.second;
		cur = got.second + 1;
	}
	if (Check(cur)) lst1 = cur, lst2 = Inf;
	while (lst1 <= lst2) {
		ll mid = lst1 + lst2 >> 1ll;
		if (Check(mid)) lst1 = mid + 1;
		else lst2 = mid - 1;
	}
	printf("%I64d\n", lst1 - 1ll);
	return 0;
}