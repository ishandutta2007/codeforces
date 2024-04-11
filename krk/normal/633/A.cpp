#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c;

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	for (int i = 0; i <= c; i += a)
		if ((c - i) % b == 0) { printf("Yes\n"); return 0; }
	printf("No\n");
	return 0;
}