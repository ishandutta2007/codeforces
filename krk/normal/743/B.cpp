#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, k;

int main()
{
	cin >> n >> k;
	while (n)
		if (k <= (1ll << n - 1ll) - 1ll) n--;
		else if (k == (1ll << n - 1ll)) { printf("%lld\n", n); break; }
		else { k -= (1ll << n - 1ll); n--; }
	return 0;
}