#include <cstdio>
#include <cmath>
using namespace std;

typedef long double ld;

const ld pi = acos(-1.0l);

int n, r, v;

int main()
{
	scanf("%d %d %d", &n, &r, &v);
	while (n--) {
		int s, f; scanf("%d %d", &s, &f);
		int d = f - s;
		ld L = 0.0, R = 4000000000.0;
		for (int i = 0; i < 70; i++) {
			ld m = (L + R) / 2;
			if (ld(v) * m + fabs(2.0l * ld(r) * sin(ld(v) * m / (2.0l * r))) >= d)
				R = m;
			else L = m;
		}
		printf("%.10lf\n", double(R));
	}
	return 0;
}