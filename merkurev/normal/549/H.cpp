#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const double eps = 1e-10;


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	double a, b, c, d;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	double dd = a * d - b * c;

	double ans = max(fabs(a), max(fabs(b), max(fabs(c), fabs(d) ) ) );
	if (fabs(dd) < eps)
		ans = 0;

	
	for (int sa = -1; sa <= 1; sa += 2)
		for (int sb = -1; sb <= 1; sb += 2)
			for (int sc = -1; sc <= 1; sc += 2)
				for (int sd = -1; sd <= 1; sd += 2)
				{
					double A = sa * sd - sb * sc;
					double B = sa * d + sd * a - sb * c - sc * b;
					double C = dd;

					if (fabs(A) < eps)
					{
						if (fabs(B) > eps)
							ans = min(ans, fabs(C / B) );
						continue;
					}

					double D = B * B - 4 * A * C;
					
	//				eprintf("%.5lf %.5lf %.5lf    %.5lf\n", A, B, C, D);
					if (D < -eps)
						continue;
					if (D < 0)
						D = 0;
					D = sqrt(D);
					double x1 = fabs( (-B + D) / (2. * A) );
					double x2 = fabs( (-B - D) / (2. * A) );
					ans = min(ans, x1);
					ans = min(ans, x2);
				}
	printf("%.10lf\n", ans);




	return 0;
}