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

const int Maxn = 100005;
const ll Inf = 9000000000000000000ll;

int n, m, q;
int a[Maxn];
int b[Maxn];
ll bval[Maxn];
ll cur;
set <ll> S;

int getOdd(int l, int r)
{
	if (l % 2 == 0) l++;
	if (r % 2 == 0) r--;
	if (l > r) return 0;
	return 1 + (r - l) / 2;
}

int getEven(int l, int r)
{
	if (l % 2) l++;
	if (r % 2) r--;
	if (l > r) return 0;
	return 1 + (r - l) / 2;
}

ll Solve(ll val)
{
	ll res = Inf;
	set <ll>::iterator it = S.lower_bound(val);
	if (it != S.end()) res = min(res, *it - val);
	if (it != S.begin()) {
		it--;
		res = min(res, val - *it);
	}
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i % 2) cur += a[i];
		else cur -= a[i]; 
	}
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	for (int i = m; i >= 1; i--)
		bval[i] = -b[i] - bval[i + 1];
	for (int i = 1; i <= 1 + m - n; i++) {
		ll my = n % 2? bval[i] + bval[i + n]: bval[i] - bval[i + n];
		S.insert(my);
	}
	printf("%I64d\n", Solve(-cur));
	while (q--) {
		int l, r, x; scanf("%d %d %d", &l, &r, &x);
		cur += ll(getOdd(l, r) - getEven(l, r)) * x;
		printf("%I64d\n", Solve(-cur));
	}
	return 0;
}