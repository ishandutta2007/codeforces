#include <bits/stdc++.h>
using namespace std;

int T;
int n, U, R, D, L;

bool Solve(int a, int b, int c, int d)
{
	return a + b <= U && U - a - b <= n - 2 &&
		   b + d <= R && R - b - d <= n - 2 &&
		   c + d <= D && D - c - d <= n - 2 &&
		   a + c <= L && L - a - c <= n - 2;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d %d", &n, &U, &R, &D, &L);
		bool ok = false;
		for (int a = 0; a < 2; a++)
			for (int b = 0; b < 2; b++)
				for (int c = 0; c < 2; c++)
					for (int d = 0; d < 2; d++)
						if (Solve(a, b, c, d)) ok = true;
		printf("%s\n", ok? "YES": "NO");
	}
    return 0;
}