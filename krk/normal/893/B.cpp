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

bool Check(int x)
{
	int a = 0;
	while (!(x & 1)) { a++; x >>= 1; }
	int b = 0;
	while (x & 1) { b++; x >>= 1; }
	return x == 0 && a + 1 == b;
}

int main()
{
	int n; scanf("%d", &n);
	int mx = 1;
	for (int i = 1; i * i <= n; i++) if (n % i == 0) {
		if (Check(i)) mx = max(mx, i);
		if (Check(n / i)) mx = max(mx, n / i);
	}
	printf("%d\n", mx);
	return 0;
}