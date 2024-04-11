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

ll r, d;
int n;
int res;

ll Sq(ll x) { return x * x; }

ll Dist(ll ax, ll ay) { return Sq(ax) + Sq(ay); }

int main()
{
	cin >> r >> d;
	scanf("%d", &n);
	while (n--) {
		ll xi, yi, ri; scanf("%I64d %I64d %I64d", &xi, &yi, &ri);
		ll dist = Dist(xi, yi);
		if (dist >= Sq(r - d + ri) && dist <= Sq(r - ri))
			res++;
	}
	printf("%d\n", res);
	return 0;
}