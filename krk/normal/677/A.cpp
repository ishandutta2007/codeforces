#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, h;
int res;

int main()
{
	scanf("%d %d", &n, &h);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (a > h) res += 2;
		else res++;
	}
	printf("%d\n", res);
	return 0;
}