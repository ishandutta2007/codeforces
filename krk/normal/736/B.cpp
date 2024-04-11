#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n;

bool Prime(int x)
{
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	if (Prime(n)) printf("1\n");
	else if (n % 2 == 0) printf("2\n");
	else if (Prime(n - 2)) printf("2\n");
	else printf("3\n");
	return 0;
}