#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200010


int main() {
	long long x[60];
	long long y[60];
	long long ax, bx, xx, ay, by, yy;
	long long sx, sy, t, k,n;
	scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &xx, &yy, &ax, &ay, &bx, &by);
	scanf("%I64d %I64d %I64d", &sx, &sy, &t);
	x[0] = xx;
	y[0] = yy;
  n=1;
	f(i, 60) {
		x[i + 1] = (x[i] * ax) + bx;
		y[i + 1] = (y[i] * ay) + by;
      n++;
		if (x[i + 1] > (sx + t))break;
		if (y[i + 1] > (sy + t))break;
	}
	k = 0;
	f(i, n) {
		f(j, i+1) {
			xx = abs(sx - x[i]) + abs(sy - y[i]);
			yy = abs(sx - x[j]) + abs(sy - y[j]);
			xx = min(xx, yy);
			yy = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			if ((xx + yy) <= t)k = max(i - j + 1,k);
		}
	}
	printf("%I64d\n", k);

	return 0;
}