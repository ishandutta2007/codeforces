#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
ll k;
ll a[Maxn];
int pnt;

ll Add(ll a, ll b) { return min(a + b, k); }

void Upgrade()
{
	for (int i = pnt + 1; i < n; i++)
		a[i] = Add(a[i], a[i - 1]);
}

ll Mult(ll a, ll b)
{
	if (a == 0 || b == 0) return 0;
	return a <= k / b? a * b: k;
}

int main()
{
	scanf("%d %I64d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
		if (a[i] >= k) { printf("0\n"); return 0; }
	}
	Upgrade();
	if (a[n - 1] >= k) { printf("1\n"); return 0; }
	while (a[pnt] == 0) pnt++;
	if (n - pnt == 2) {
		ll dom = (k - a[n - 1]) / a[n - 2];
		if (dom * a[n - 2] + a[n - 1] < k) dom++;
		dom++;
		printf("%I64d\n", dom); return 0;
	}
	if (n - pnt == 3) {
		ll lef = 0, rig = 2000000000;
		while (lef <= rig) {
			ll mid = lef + rig >> 1;
			ll cand = Mult((mid + 1) * mid / 2, a[pnt]);
			cand = Add(cand, Mult(mid, a[pnt + 1]));
			cand = Add(cand, a[pnt + 2]);
			if (cand >= k) rig = mid - 1;
			else lef = mid + 1;
		}
		rig += 2;
		printf("%I64d\n", rig); return 0;
	}
	ll res = 1;
	while (a[n - 1] < k) {
		Upgrade(); res++;
	}
	printf("%I64d\n", res);
	return 0;
}