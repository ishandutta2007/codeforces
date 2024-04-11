#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll lim = 2000000000;
const int Maxn = 200005;

int n;
int c[Maxn], d[Maxn];

int Div(ll rat) { return rat >= 1900? 1: 2; }

int Status(ll cur)
{
	for (int i = n - 1; i >= 0; i--) {
		cur -= c[i];
		if (Div(cur) < d[i]) return 1;
		if (Div(cur) > d[i]) return -1;
	}
	return 0;
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &c[i], &d[i]);
	ll lef = -lim, rig = lim;
	ll res = lim + 1;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		int st = Status(mid);
		if (st == 1) rig = mid - 1;
		else if (st == -1) lef = mid + 1;
		else {
			res = mid; lef = mid + 1;
		}
	}
	if (res > lim) printf("Impossible\n");
	else if (res == lim) printf("Infinity\n");
	else printf("%I64d\n", res);
    return 0;
}