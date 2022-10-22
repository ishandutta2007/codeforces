#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	int x = n / k * k;
	while (x <= n) x += k;
	printf("%d\n", x);
	return 0;
}