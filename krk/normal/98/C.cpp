#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long double ld;

int a, b, l;

ld getW(ld ang) { return b * cos(ang) + a * sin(ang) - l * sin(ang) * cos(ang); }

int main()
{
	scanf("%d %d %d", &a, &b, &l);
	if (l <= a) { printf("%d.0\n", min(l, b)); return 0; }
	if (l <= b) { printf("%d.0\n", min(l, a)); return 0; }
	ld lef = 0.0l, rig = acos(0.0l);
	for (int i = 0; i < 1000; i++) {
		ld q1 = (2.0l * lef + rig) / 3.0l, q2 = (lef + 2.0l * rig) / 3.0l;
		ld f1 = getW(q1), f2 = getW(q2);
		if (f1 <= f2) rig = q2;
		else lef = q1;
	}
	ld res = min(min(ld(a), ld(b)), min(ld(l), getW(lef)));
	if (res > 1e-8) cout << fixed << setprecision(15) << res << endl;
	else printf("My poor head =(\n");
	return 0;
}