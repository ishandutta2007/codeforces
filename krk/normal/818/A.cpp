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

int main()
{
	cin >> n >> k;
	ll x = n / 2 / (k + 1);
	printf("%I64d %I64d %I64d\n", x, k * x, n - (k + 1) * x);
	return 0;
}