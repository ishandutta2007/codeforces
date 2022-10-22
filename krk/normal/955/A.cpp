#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int h, m;
int H, D, C, N;

int main()
{
	scanf("%d %d", &h, &m);
	int my = h * 60 + m;
	int nd = 20 * 60;
	scanf("%d %d %d %d", &H, &D, &C, &N);
	ld res = ((H - 1) / N + 1) * ld(C);
	if (my < nd) H += D * (nd - my);
	res = min(res, ((H - 1) / N + 1) * ld(C) * 0.8l);
	cout << fixed << setprecision(8) << res << endl;
	return 0;
}