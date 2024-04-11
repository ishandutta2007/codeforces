#include <cstdio>
#include <algorithm>
using namespace std;

int X1, Y1, X2, Y2;

int main()
{
	scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
	if (X1 == X2) { int side = abs(Y1 - Y2); printf("%d %d %d %d\n", X1 + side, Y1, X2 + side, Y2); }
	else if (Y1 == Y2) { int side = abs(X1 - X2); printf("%d %d %d %d\n", X1, Y1 + side, X2, Y2 + side); }
	else {
		int asid = abs(X1 - X2), bsid = abs(Y1 - Y2);
		if (asid == bsid) printf("%d %d %d %d\n", X1, Y2, X2, Y1);
		else printf("-1\n");
	}
	return 0;
}