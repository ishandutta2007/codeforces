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

const int Maxn = 300005;

int n;
bool was[Maxn];

int main()
{
	printf("1");
	scanf("%d", &n);
	int pnt = n;
	for (int i = 1; i <= n; i++) {
		int p; scanf("%d", &p);
		was[p] = true;
		while (was[pnt]) pnt--;
		printf(" %d", i + 1 - (n - pnt));
	}
	printf("\n");
	return 0;
}