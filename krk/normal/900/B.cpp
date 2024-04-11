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

const int Maxn = 1000005;

int a, b, c;
bool was[Maxn];

int main()
{
	cin >> a >> b >> c;
	for (int i = 1; ; i++) {
		a *= 10;
		if (was[a]) break;
		was[a] = true;
		int cur = a / b; a %= b;
		if (cur == c) { printf("%d\n", i); return 0; }
	}
	printf("-1\n");
	return 0;
}