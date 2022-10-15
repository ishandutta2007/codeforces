/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef long double LD;

LL n, t, k, d;

int main() {
	cin >> n >> t >> k >> d;
	LL t1 = (n / k + !!(n % k)) * t;
	if (t1 <= d + t) printf("NO");
	else printf("YES");

	return 0;
}