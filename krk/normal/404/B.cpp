#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int Maxd = 4;
const int dy[Maxd] = {0, 1, 0, -1};
const int dx[Maxd] = {1, 0, -1, 0};

double a, d;
double mx[Maxd], my[Maxd];
double curx, cury;
int ang;
int n;

int main()
{
	scanf("%lf %lf", &a, &d);
	int dv = d / (4.0 * a); d -= dv * 4.0 * a;
	mx[0] = 0; my[0] = 0;
	mx[1] = a; my[1] = 0;
	mx[2] = a; my[2] = a;
	mx[3] = 0; my[3] = a;
	scanf("%d", &n);
	while (n--) {
		double go = d;
		while (fabs(mx[(ang + 1) % Maxd] - curx) + fabs(my[(ang + 1) % Maxd] - cury) <= go) {
			go -= fabs(mx[(ang + 1) % Maxd] - curx) + fabs(my[(ang + 1) % Maxd] - cury);
			ang = (ang + 1) % Maxd; curx = mx[ang]; cury = my[ang];
		}
		curx += go * dx[ang]; cury += go * dy[ang];
		printf("%.10lf %.10lf\n", curx, cury);
	}
	return 0;
}