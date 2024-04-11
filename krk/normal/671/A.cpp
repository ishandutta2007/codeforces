#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <ld, int> ldi;

int ax, ay, bx, by, tx, ty;
int n;
ldi mna[2], mnb[2];
ld res;

ld Dist(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

void Insert(ldi mn[], ldi cur)
{
	if (cur.first < mn[0].first) mn[1] = mn[0], mn[0] = cur;
	else if (cur.first < mn[1].first) mn[1] = cur;
}

int main()
{
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty);
	scanf("%d", &n);
	mna[0] = mna[1] = mnb[0] = mnb[1] = ldi(1e30, -1);
	for (int i = 0; i < n; i++) {
		double x, y; scanf("%lf %lf", &x, &y);
		ld X = x, Y = y;
		res += 2.0l * Dist(X - tx, Y - ty);
		Insert(mna, ldi(Dist(X - ax, Y - ay) - Dist(X - tx, Y - ty), i));
		Insert(mnb, ldi(Dist(X - bx, Y - by) - Dist(X - tx, Y - ty), i));
	}
	ld ans = min(res + mna[0].first, res + mnb[0].first);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) if (mna[i].second != mnb[j].second)
			ans = min(ans, res + mna[i].first + mnb[j].first);
	cout << fixed << setprecision(15) << ans << endl;
	return 0;
}