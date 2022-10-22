#include <cstdio>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxt = 4001;
const int Maxh = 201;
const double eps = 1e-8;

int hp1, dt1, l1, r1;
double p1;
int hp2, dt2, l2, r2;
double p2;
double P1[Maxt][Maxh], P2[Maxt][Maxh];
double res;

void Calc(double P[][Maxh], int hp1, int l2, int r2, double p2)
{
	P[0][hp1] = 1.0;
	for (int i = 0; i + 1 < Maxt; i++) {
		for (int j = 0; j <= hp1; j++) if (P[i][j] >= eps) {
			for (int k = l2; k <= r2; k++)
				P[i + 1][max(0, j - k)] += P[i][j] / (r2 - l2 + 1) * (1.0 - p2);
			P[i + 1][j] += P[i][j] * p2;
		}
	}
}

int main()
{
	int p;
	scanf("%d %d %d %d %d", &hp1, &dt1, &l1, &r1, &p); p1 = p / 100.0;
	if (p == 100) { printf("0.00000\n"); return 0; }
	scanf("%d %d %d %d %d", &hp2, &dt2, &l2, &r2, &p); p2 = p / 100.0;
	if (p == 100) { printf("1.00000\n"); return 0; }
	Calc(P1, hp1, l2, r2, p2); Calc(P2, hp2, l1, r1, p1);
	int tim1 = 0, tim2 = -dt2, sh = 0;
	for (int i = 1; i < Maxt && sh < Maxt; i++) {
		res += (1.0 - P1[sh][0]) * (P2[i][0] - P2[i - 1][0]);
		tim1 += dt1;
		while (tim2 + dt2 < tim1) { tim2 += dt2; sh++; }
	}
	printf("%.10lf\n", res);
	return 0;
}