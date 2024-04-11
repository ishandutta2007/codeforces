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

int n;
ll k;
vector <int> V;

bool Ok(ll n)
{
	return n - 1 <= 2ll * k / ll(n);
}

void Gen(int lvl)
{
	while (lvl <= k && n > 0) {
		n--; k -= lvl;
		printf("("); Gen(lvl + 1); printf(")");
	}
}

int main()
{
	scanf("%d %lld", &n, &k);
	if (k > ll(n) * (n - 1) / 2) { printf("Impossible\n"); return 0; }
	Gen(0);
	printf("\n");
	return 0;
}