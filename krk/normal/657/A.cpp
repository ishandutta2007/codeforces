#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, d, h;

int main()
{
	scanf("%d %d %d", &n, &d, &h);
	if (d > 2 * h) { printf("-1\n"); return 0; }
	if (d == 1 && n != 2) { printf("-1\n"); return 0; }
	for (int i = 1; i <= h; i++)
		printf("%d %d\n", i, i + 1);
	int p = 1, nxt = h + 2;
	for (int i = 1; i <= d - h; i++) {
		printf("%d %d\n", p, nxt);
		p = nxt; nxt++;
	}
	while (nxt <= n) {
		printf("%d %d\n", h, nxt);
		nxt++;
	}
	return 0;
}