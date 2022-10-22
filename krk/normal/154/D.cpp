#include <cstdio>
using namespace std;

int x1, x2, a, b;

void Solve(int h, int lo, int hi, int &res1, int &res2)
{
	if (lo <= 0 && 0 <= hi)
		if (lo <= -h) { res1 = 1; res2 = h; }
		else res1 = 0;
	else if (lo >= 0) res1 = 0;
	else {
		int a = -hi, b = -lo;
		h %= a + b;
		if (a <= h && h <= b) { res1 = 1; res2 = h; }
		else if (h) res1 = 0;
			 else res1 = -1; 
	}
}

int main()
{
	scanf("%d %d %d %d", &x1, &x2, &a, &b);
	int res1, res2;
	if (x1 < x2) {
		Solve(x2 - x1, -b, -a, res1, res2);
		if (res1 == -1) printf("SECOND\n");
		else if (res1 == 0) printf("DRAW\n");
		else if (res1 == 1) printf("FIRST\n%d\n", x1 + res2);
	} else {
		Solve(x1 - x2, a, b, res1, res2);
		if (res1 == -1) printf("SECOND\n");
		else if (res1 == 0) printf("DRAW\n");
		else if (res1 == 1) printf("FIRST\n%d\n", x1 - res2);
	}
	return 0;
}