#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);

int n, m;
vector <int> X, Y;

double Dot(double ax, double ay, double bx, double by) { return ax * bx + ay * by; }

double Len(double ax, double ay) { return sqrt(ax * ax + ay * ay); }

void Rot(double &x, double &y, double ang)
{
	double nx = cos(ang) * x - sin(ang) * y;
	double ny = sin(ang) * x + cos(ang) * y;
	x = nx; y = ny;
}

int main()
{
	scanf("%d %d", &n, &m);
	if (m == 3)
		if (n > 4) printf("-1\n");
		else {
			printf("0 0\n");
			printf("3 0\n");
			printf("0 3\n");
			if (n == 4) printf("1 1\n");
		}
	else {
		double dx = 0, dy = 100000;
		int x = 0, y = 0;
		X.clear(); Y.clear(); X.push_back(x); Y.push_back(y);
		for (int i = 2; i <= m; i++) {
			x += int(dx); y += int(dy);
			X.push_back(x); Y.push_back(y);
			Rot(dx, dy, -2.0 * pi / m);
		}
		for (int i = 0; i < X.size(); i++)
			printf("%d %d\n", X[i], Y[i]);
		for (int i = 0; i < n - m; i++) {
			double ax = X[i] - X[(i - 1 + m) % m], ay = Y[i] - Y[(i - 1 + m) % m];
			double bx = X[(i + 1) % m] - X[i], by = Y[(i + 1) % m] - Y[i];
			double alen = Len(ax, ay), blen = Len(bx, by);
			double ang = acos(Dot(ax, ay, bx, by) / alen / blen);
			Rot(ax, ay, - pi / 2.0 - ang / 2.0);
			ax *= 1000.0 / alen; ay *= 1000.0 / alen;
			int addx = int(ax), addy = int(ay); addx += 10.0 * (addx >= 0);
			printf("%d %d\n", X[i] + addx, Y[i] + int(ay) + addy);
		}
	}
	return 0;
}