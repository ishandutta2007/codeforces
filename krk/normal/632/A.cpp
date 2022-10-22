#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, p;
ll app;
ll res;

int main()
{
	scanf("%d %d", &n, &p);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s != "half") app |= 1ll << ll(i);
	}
	while (app) {
		res += ll(app) * p / 2;
		app /= 2;
	}
	printf("%I64d\n", res);
	return 0;
}