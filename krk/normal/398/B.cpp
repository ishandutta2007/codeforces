#include <cstdio>
using namespace std;

const int Maxn = 2005;

int n, m;
int N;
int R[Maxn], C[Maxn];
int tr, tc;
double f[Maxn][Maxn];
bool calc[Maxn][Maxn];

double F(int r, int c)
{
	if (r > n || c > n) return 0.0;
	if (r == n && c == n) return 0.0;
	if (!calc[r][c]) {
		calc[r][c] = true;
		int A = (n - r) * (n - c);
		int B = (n - r) * c;
		int C = r * (n - c);
		int D = r * c;
		double S = 1 + (F(r + 1, c + 1) * A + F(r + 1, c) * B + F(r, c + 1) * C) / N;
		double V = 1.0 - double(D) / N;
		f[r][c] = S / V; 
	}
	return f[r][c];
}

int main()
{
	scanf("%d %d", &n, &m); N = n * n;
	while (m--) {
		int r, c; scanf("%d %d", &r, &c);
		if (R[r]++ == 0) tr++;
		if (C[c]++ == 0) tc++;
	}
	printf("%.10lf\n", F(tr, tc));
	return 0;
}