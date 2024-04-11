#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;


int main() {
	ll n;
	char c;
	scanf("%lld%c", &n, &c);
	--n;
	ll ans = (n / 4) * 16;
	n %= 2;
	if (n == 1)
		ans += 7;
	if (c == 'f')
		ans += 1;
	else if (c == 'e')
		ans += 2;
	else if (c == 'd')
		ans += 3;
	else if (c == 'a')
		ans += 4;
	else if (c == 'b')
		ans += 5;
	else
		ans += 6;
	cout << ans << "\n";
	return 0;
}