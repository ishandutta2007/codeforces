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

ll l, r, x, y, k;

int main()
{
	cin >> l >> r >> x >> y >> k;
	for (ll i = x; i <= y; i++)
		if (l <= i * k && i * k <= r) {
			printf("YES\n"); return 0;
		}
	printf("NO\n");
	return 0;
}