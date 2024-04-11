#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, a, b;

int main()
{
	scanf("%d %d %d", &n, &a, &b); a--;
	b %= n;
	b = (b + n) % n;
	printf("%d\n", (a + b) % n + 1);
	return 0;
}