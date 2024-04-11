#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int a, b, c;

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	int tk = min(a, min(b / 2, c / 4));
	printf("%d\n", tk + 2 * tk + 4 * tk);
	return 0;
}