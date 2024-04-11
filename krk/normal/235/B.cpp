#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n;
double p[Maxn];
double f[Maxn];
double F, A, P, D;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%lf", &p[i]);
	p[n] = 0.0;
	for (int i = n - 1; i >= 0; i--) {
		F = (1.0 - p[i]) * f[i + 1] + p[i] * F;
		D = p[i] * (D + (1.0 - p[i + 1]) + 2.0 * P);
		A = p[i] * A + D;
		P = p[i] * (1.0 - p[i + 1] + P);
		f[i] = F + A;
	}
	printf("%.15lf\n", f[0]);
	return 0;
}