#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int Maxn = 105;
const int Maxm = 5005;
const double Inf = 1e50;
const double eps = 1e-6;

int n, m;
int a[Maxm], b[Maxm], c[Maxm];
double mat[Maxn][Maxn];
bool taken[Maxn];
double w[Maxn];
double res;

void Take(int v)
{
	taken[v] = true;
	for (int i = 1; i <= n; i++)
		if (mat[v][i] > 0 && !taken[i]) Take(i);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		mat[a[i]][b[i]] += 1; mat[b[i]][a[i]] += 1;
		mat[a[i]][a[i]] -= 1; mat[b[i]][b[i]] -= 1;
	}
	Take(1);
	if (!taken[n]) {
		for (int i = 0; i <= m; i++)
			printf("0.00000\n");
		return 0;
	}
	for (int j = 1; j <= n; j++) mat[1][j] = mat[n][j] = 0.0;
	mat[1][1] = 1.0; mat[1][n + 1] = 0.0;
	mat[n][n] = 1.0; mat[n][n + 1] = 1.0;
	for (int j = 1; j <= n; j++) {
		int bi = j;
		for (int i = j + 1; i <= n; i++) 
			if (fabs(mat[i][j]) > fabs(mat[bi][j])) bi = i;
		if (bi != j)
			for (int k = 1; k <= n + 1; k++) swap(mat[j][k], mat[bi][k]);
		if (fabs(mat[j][j]) < eps) continue;
		for (int i = 1; i <= n; i++) if (i != j) {
			double koef = mat[i][j] / mat[j][j];
			for (int k = 1; k <= n + 1; k++) mat[i][k] -= koef * mat[j][k];
		}
	}
	for (int i = 1; i <= n; i++) w[i] = mat[i][n + 1] / mat[i][i];
	double rate = Inf;
	for (int i = 0; i < m; i++) rate = min(rate, double(c[i]) / fabs(w[a[i]] - w[b[i]]));
	for (int i = 1; i <= n; i++) w[i] *= rate;
	for (int i = 0; i < m; i++)
		if (a[i] == 1 || b[i] == 1) res += a[i] == 1? w[b[i]] - w[a[i]]: w[a[i]] - w[b[i]];
	printf("%.10lf\n", res);
	for (int i = 0; i < m; i++)
		printf("%.10lf\n", w[b[i]] - w[a[i]]);
	return 0;
}