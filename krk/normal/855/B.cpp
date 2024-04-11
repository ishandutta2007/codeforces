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

const ll Inf = 4000000000000000000ll;

int n;
ll p, q, r;
ll mx1 = -Inf, mx2 = -Inf, mx3 = -Inf;

int main()
{
	cin >> n >> p >> q >> r;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		mx1 = max(mx1, ll(a) * p);
		mx2 = max(mx2, mx1 + ll(a) * q);
		mx3 = max(mx3, mx2 + ll(a) * r);
	}
	cout << mx3 << endl;
	return 0;
}