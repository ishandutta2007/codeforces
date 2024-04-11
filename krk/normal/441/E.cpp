#include <cstdio>
using namespace std;

const int Maxk = 205;

int x, k, p;
double mp;
double prob[Maxk][Maxk][Maxk];
double res;

int Get(int x)
{
	int res = 0;
	while (x % 2 == 0) { res++; x /= 2; }
	return res;
}

int main()
{
	scanf("%d %d %d", &x, &k, &p);
	mp = double(p) / 100;
	prob[0][0][0] = 1;
	for (int i = 0; i < k; i++)
		for (int j = 0; j + 1 < Maxk; j++)
			for (int l = 0; l + 1 < Maxk; l++) {
				if (l % 2 == 0) {
					prob[i + 1][j + 1][l / 2] += mp * prob[i][j][l];
					res += mp * prob[i][j][l];
				}
				prob[i + 1][j][l + 1] += (1.0 - mp) * prob[i][j][l];
			}
	for (int j = 0; j < Maxk; j++)
		for (int l = 0; l < Maxk; l++)
			res += prob[k][j][l] * Get(x + l);
	printf("%.13lf\n", res);
	return 0;
}