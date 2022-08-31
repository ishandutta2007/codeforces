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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int maxn = (int) 3e4 + 100;
char str[maxn];
const int maxh = 31;

double expA[maxn][maxh][2];
double probA[maxn][maxh][2];

double expAS[maxn][maxh][2];
double probAS[maxn][maxh][2];

void add(double &e1, double &p1, double e2, double p2)
{
	if (p1 + p2 == 0)
		return;
	e1 = (e1 * p1 + e2 * p2) / (p1 + p2);
	p1 = p1 + p2;
}

double solveA(int n, int h)
{
	expA[0][0][0] = 1.;
	probA[0][0][0] = 1.;
	
	double ans = 0;
	
	for (int i = 0; i < n; i++)
	{
//		eprintf("Before:\n");
		for (int ph = 0; ph < h; ph++)
			for (int onB = 0; onB <= 1; onB++)
			{
				double curexp = expA[i][ph][onB];
				double curp = probA[i][ph][onB];

//				eprintf("i = %d ph = %d onB = %d : exp = %.5lf prob = %.5lf\n", i, ph, onB, curexp, curp);

				for (int curH = 1; curH <= (onB ? ph + 1 : h); curH++)
				{
					double probH = 1. / (double)(1 << (curH - (curH == h ? 1 : 0) ) );
					double nprob = curp * probH;
					if (curH <= ph)
					{
						add(expA[i + 1][ph][onB], probA[i + 1][ph][onB], curexp, nprob);
					}
					else
					{
//						eprintf("i = %d, curH = %d, onB = %d, nprob = %.5lf\n", i, curH, onB, nprob);
						add(expAS[i][curH][onB], probAS[i][curH][onB], curexp, nprob);
//						eprintf("%.5lf\n", probAS[i][curH][onB] );
					}
				}
			}

//		eprintf("Building:\n");
		for (int ph = 1; ph <= h; ph++)
			for (int onB = 0; onB <= 1; onB++)
			{
				double curexp = expAS[i][ph][onB];
				double curp = probAS[i][ph][onB];
				
//				eprintf("i = %d ph = %d onB = %d : exp = %.5lf prob = %.5lf\n", i, ph, onB, curexp, curp);
				
				if (i == n - 1)
				{
					ans += curexp * curp;
				}

				for (int curH = 0; curH < ph; curH++)
				{
					int nonB = onB;
					if (curH < ph - 1)
						nonB = 1;

					double nexp = curexp + (1 << curH);

					add(expA[i + 1][curH][nonB], probA[i + 1][curH][nonB], nexp, curp);
				}
			}
	}
	return ans;
}

double expB[maxn][maxh][2];
double probB[maxn][maxh][2];

double expBS[maxn][maxh][2];
double probBS[maxn][maxh][2];

double solveB(int n, int h)
{
	probB[0][0][0] = 1;
	expB[0][0][0] = 1;

	double ans = 0, ansp = 0;

	for (int i = 0; i < n; i++)
	{
//		eprintf("Before:\n");
		for (int ph = 0; ph < h; ph++)
			for (int onB = 0; onB <= 1; onB++)
			{
				double curexp = expB[i][ph][onB];
				double curp = probB[i][ph][onB];

//				eprintf("i = %d ph = %d onB = %d : exp = %.5lf prob = %.5lf\n", i, ph, onB, curexp, curp);

				if (ph != 0)
				{
					double probBig = 1. / (1 << ph);
					curexp += 1. / probBig - 1;
				}

				for (int curH = ph + 1; curH <= (onB ? ph + 1 : h); curH++)
				{
					double probH = 1. / (double)(1 << (curH - (curH == h ? 1 : 0) ) );
					double nprob = curp * probH;
//					eprintf("i = %d, curH = %d, onB = %d, nprob = %.5lf\n", i, curH, onB, nprob);
					add(expBS[i][curH][onB], probBS[i][curH][onB], curexp, nprob);
//					eprintf("%.5lf\n", probBS[i][curH][onB] );
				}
			}

//		eprintf("Building:\n");
		for (int ph = 1; ph <= h; ph++)
			for (int onB = 0; onB <= 1; onB++)
			{
				double curexp = expBS[i][ph][onB];
				double curp = probBS[i][ph][onB];
				
				if (i == n - 1)
				{
					add(ans, ansp, curexp, curp);
				}

//				eprintf("i = %d ph = %d onB = %d : exp = %.5lf prob = %.5lf\n", i, ph, onB, curexp, curp);
				
				for (int curH = 0; curH < ph; curH++)
				{
					int nonB = onB;
					if (curH < ph - 1)
						nonB = 1;

					int nit = i + (1 << curH);
					if (nit > n - 1)
						continue;

					double nexp = curexp + 1;
//					eprintf("curH = %d, nonB = %d, nit = %d, nexp = %.5lf\n", curH, nonB, nit, nexp);
					add(expB[nit][curH][nonB], probB[nit][curH][nonB], nexp, curp);
				}
			}
	}
	return ans;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%s", str);
	int n, h;
	scanf("%d%d", &n, &h);
	h++;
	double ans;
	if (str[0] == 'A')
	{
		ans = solveA(n, h);
	}
	else
	{
		ans = solveB(n, h);
	}
	printf("%.10lf\n", ans);

	return 0;
}