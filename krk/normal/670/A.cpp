#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
int res1, res2;

int main()
{
	scanf("%d", &n);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur >= 5) res1++;
		cur = (cur + 1) % 7;
	}
	cur = 5;
	for (int i = 0; i < n; i++) {
		if (cur >= 5) res2++;
		cur = (cur + 1) % 7;
	}
	printf("%d %d\n", res1, res2);
	return 0;
}