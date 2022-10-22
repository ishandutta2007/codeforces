#include <cstdio>
#include <cmath>
using namespace std;

const int Maxn = 5005;

int n, T;
int p[Maxn], t[Maxn];
double pd[Maxn];
double dp[Maxn][Maxn];
double res;

double toPower(double a, int p)
{
	if (p < 0) return 0;
	double res = 1.0;
	while (p) {
		if (p & 1) res = res * a;
		p >>= 1; a = a * a;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &T);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &p[i], &t[i]);
		pd[i] = double(p[i]) / 100;
	}
	pd[n + 1] = 0; t[n + 1] = T;
	dp[0][0] = 1;
	double dv = 0;
	for (int i = 0; i <= n; i++) {
		double sum = 0.0, lst = 0.0;
		int l = 0;
		double coef = toPower(1.0 - pd[i + 1], t[i + 1] - 1);
		for (int r = 0; r < T; r++) {
			sum = (1.0 - pd[i + 1]) * sum + dp[i][r];
			if (r - l + 1 >= t[i + 1]) { sum -= coef * dp[i][l]; lst = dp[i][l]; l++; }
			dp[i + 1][r + 1] = lst * coef + sum * pd[i + 1]; 
		}
		sum = (1.0 - pd[i + 1]) * sum + dp[i][T];
		res += sum * i; dv += sum;
	}
	printf("%.9lf\n", res / dv);
	return 0;
}