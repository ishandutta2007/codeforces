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

int a, b, p;
ll x;
ll res;

int Inv(int x)
{
	int pw = p - 2;
	int res = 1;
	while (pw) {
		if (pw & 1) res = ll(res) * x % p;
		pw >>= 1; x = ll(x) * x % p;
	}
	return res;
}

int main()
{
	scanf("%d %d %d %I64d", &a, &b, &p, &x);
	int cur = 1;
	a = Inv(a);
	for (int i = 0; i < p - 1; i++) {
		int nd = ll(b) * cur % p;
		ll my = i;
		if (my == 0) my += p - 1;
		int dif = (my - nd + p) % p;
		my += ll(dif) * (p - 1);
		if (my <= x)
			res += (x - my) / (ll(p) * (p - 1)) + 1;
		cur = ll(cur) * a % p;
	}
	printf("%I64d\n", res);
	return 0;
}