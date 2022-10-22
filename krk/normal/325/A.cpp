#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 2000000000;

int n;
int xl = Inf, xr = -Inf, yl = Inf, yr = -Inf;
int s;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int X1, Y1, X2, Y2; scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		s += (X2 - X1) * (Y2 - Y1);
		xl = min(xl, X1); xr = max(xr, X2);
		yl = min(yl, Y1); yr = max(yr, Y2);
	}
	printf("%s\n", s == (xr - xl) * (yr - yl) && xr - xl == yr - yl? "YES": "NO");
	return 0;
}