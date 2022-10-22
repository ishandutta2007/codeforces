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

const int Maxn = 1000005;

int n, m, k;
bool hole[Maxn];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	while (m--) {
		int a; scanf("%d", &a);
		hole[a] = true;
	}
	int cur = 1;
	while (k-- > 0 && !hole[cur]) {
		int a, b; scanf("%d %d", &a, &b);
		if (cur == a) cur = b;
		else if (cur == b) cur = a;
	}
	printf("%d\n", cur);
	return 0;
}