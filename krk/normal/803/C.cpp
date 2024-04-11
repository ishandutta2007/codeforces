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

ll n, k;
vector <ll> dvs;

bool Check(ll lim)
{
	return k <= 2 * lim / (k + 1);
}

int main()
{
	scanf("%I64d %I64d", &n, &k);
	for (ll i = 1; i * i <= n; i++)
		if (n % i == 0) {
			dvs.push_back(i);
			if (i * i != n) dvs.push_back(n / i);
		}
	sort(dvs.begin(), dvs.end());
	for (int i = int(dvs.size()) - 1; i >= 0; i--)
		if (Check(n / dvs[i])) {
			for (ll j = 1; j < k; j++) {
				printf("%I64d ", j * dvs[i]);
				n -= j * dvs[i];
			}
			printf("%I64d\n", n);
			return 0;
		}
	printf("-1\n");
	return 0;
}