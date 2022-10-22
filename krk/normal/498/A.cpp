#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ld;

const ld eps = 1e-8;

const int Maxn = 305;

int X1, Y1, X2, Y2;
ld mA, mB, mC;
int n;
int A, B, C;
int res;

int main()
{
	scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
	mA = Y2 - Y1; mB = X1 - X2; mC = mA * X1 + mB * Y1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &A, &B, &C); C = -C;
		ld det = mA * B - A * mB;
		ld x = (B * mC - mB * C) / det;
		ld y = (mA * C - A * mC) / det;
		res += min(X1, X2) <= x + eps && x <= max(X1, X2) + eps &&
			   min(Y1, Y2) <= y + eps && y <= max(Y1, Y2) + eps;
	}
	printf("%d\n", res);
	return 0;
}