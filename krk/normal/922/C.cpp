#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, k;

int main()
{
	scanf("%I64d %I64d", &n, &k);
	for (ll i = 1; i <= k; i++)
		if (n % i != i - 1) { printf("No\n"); return 0; }
	printf("Yes\n");
	return 0;
}