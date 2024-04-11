#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	if (n == 1) printf("-1\n");
	else printf("%d %d %d\n", n, n + 1, n * (n + 1));
	return 0;
}