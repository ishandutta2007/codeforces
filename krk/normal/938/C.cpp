#include <bits/stdc++.h>
using namespace std;

int t;
int x;

void Solve(int x)
{
	if (x == 0) { printf("1 1\n"); return; }
	for (int i = 1; i * i <= x; i++) if (x % i == 0) {
		int c = i, d = x / i;
		if ((c + d) % 2 == 0) {
			int a = (c + d) / 2;
			int b = a - c;
			if (a >= b && b > 0) {
				int m = a / b;
				if (a / m == b) {
					printf("%d %d\n", a, m); return;
				}
			}
		}
	}
	printf("-1\n");
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		Solve(x);
	}
	return 0;
}