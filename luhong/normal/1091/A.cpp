#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <bitset>

int main()
{
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	int Min = std::min(a, std::min(b - 1, c - 2));
	printf("%d\n", 3 * Min + 3);
}