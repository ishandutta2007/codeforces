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

int n;
int sum;
int m;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		sum += a;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int l, r; scanf("%d %d", &l, &r);
		if (sum <= r) { printf("%d\n", max(l, sum)); return 0; }
	}
	printf("-1\n");
	return 0;
}