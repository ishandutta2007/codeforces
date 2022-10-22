#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 100005;

int n;
int RX1, RY1, RX2, RY2;
int X[Maxn], Y[Maxn], DX[Maxn], DY[Maxn];

int Status(ld tim)
{
	int res = 0;
	for (int i = 0; i < n; i++) {
		ld myX = X[i] + ld(DX[i]) * tim;
		ld myY = Y[i] + ld(DY[i]) * tim;
		if (myX <= RX1)
			return DX[i] < 0? 1: -1;
		if (myX >= RX2)
			return DX[i] > 0? 1: -1;
		if (myY <= RY1)
			return DY[i] < 0? 1: -1;
		if (myY >= RY2)
			return DY[i] > 0? 1: -1;
	}
	return 0;
}

int Count(ld tim)
{
	int res = 0;
	for (int i = 0; i < n; i++) {
		ld myX = X[i] + ld(DX[i]) * tim;
		ld myY = Y[i] + ld(DY[i]) * tim;
		res += RX1 < myX && myX < RX2 && RY1 < myY && myY < RY2;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	scanf("%d %d %d %d", &RX1, &RY1, &RX2, &RY2);
	if (RX1 > RX2) swap(RX1, RX2);
	if (RY1 > RY2) swap(RY1, RY2);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", &X[i], &Y[i], &DX[i], &DY[i]);
	ld lef = 0, rig = 1000000;
	ld res = 0.0;
	for (int i = 0; i < 100; i++) {
		ld m = (lef + rig) / 2;
		int r = Status(m);
		if (r == 1) rig = m;
		else if (r == -1) lef = m;
		else { res = m; rig = m; }
	}
	if (Count(res) >= n) cout << fixed << setprecision(15) << res << endl;
	else printf("-1\n");
	return 0;
}