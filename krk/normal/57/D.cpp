#include <cstdio>
using namespace std;

typedef long double ld;

const int Maxn = 1005;

int n, m;
char B[Maxn][Maxn];
int inrow[Maxn], incol[Maxn], tot;
int T[Maxn][Maxn];
int y, x;
ld sum;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &B[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (B[i][j] == '.') {
				inrow[i]++; incol[j]++; tot++;
			} else sum -= 4 * (i * (n - 1 - i) + j * (m - 1 - j));
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
			if (B[i][j] == '.') {
				T[i][j] = j < m - 1? T[i][j + 1]: 0;
				sum += 4 * T[i][j]; 
			} else T[i][j] = (m - 1 - j) + (i + 1 < n? T[i + 1][j]: 0);
	for (int i = 0; i < n; i++)
		for (int j = m - 1; j >= 0; j--)
			if (B[i][j] == '.') {
				T[i][j] = j < m - 1? T[i][j + 1]: 0;
				sum += 4 * T[i][j];
			} else T[i][j] = (m - 1 - j) + (i - 1 >= 0? T[i - 1][j]: 0);
	for (int j = m - 1; j >= 0; j--)
		for (int i = n - 1; i >= 0; i--)
			if (B[i][j] == '.') {
				T[i][j] = i < n - 1? T[i + 1][j]: 0;
				sum += 4 * T[i][j];
			} else T[i][j] = (n - 1 - i) + (j + 1 < m? T[i][j + 1]: 0);
	for (int j = 0; j < m; j++)
		for (int i = n - 1; i >= 0; i--)
			if (B[i][j] == '.') {
				T[i][j] = i < n - 1? T[i + 1][j]: 0;
				sum += 4 * T[i][j];
			} else T[i][j] = (n - 1 - i) + (j - 1 >= 0? T[i][j - 1]: 0);
	int accy = 0;
	for (int i = 0; i < n; i++)
		y += (i + 1) * inrow[i];
	for (int i = 0; i < n; i++) {
		y += accy - (tot - accy); accy += inrow[i];
		int accx = 0;
		x = 0;
		for (int j = 0; j < m; j++)
			x += (j + 1) * incol[j];
		for (int j = 0; j < m; j++) {
			x += accx - (tot - accx); accx += incol[j];
			if (B[i][j] == '.') sum += x + y;
		}
	}
	printf("%.12lf\n", double(sum / (ld(tot) * ld(tot))));
	return 0;
}