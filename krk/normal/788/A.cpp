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
const ll Inf = 1000000000000000000ll;

int n;
int a[Maxn];
ll cur, mx = -Inf;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	bool add = true;
	for (int i = 0; i + 1 < n; i++) {
		ll got = abs(a[i + 1] - a[i]);
		if (add) cur += got;
		else cur -= got;
		add = !add;
		mx = max(mx, cur);
		if (cur < 0) cur = 0;
	}
	add = false; cur = 0;
	for (int i = 0; i + 1 < n; i++) {
		ll got = abs(a[i + 1] - a[i]);
		if (add) cur += got;
		else cur -= got;
		add = !add;
		mx = max(mx, cur);
		if (cur < 0) cur = 0;
	}
	printf("%I64d\n", mx);
	return 0;
}