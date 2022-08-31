#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;


int win(int a, int d, int _h, int _a, int _d)
{
	int A = max(0, a - _d);
	int _A = max(0, _a - d);
	if (A == 0)
		return -1;
	if (_A == 0)
		return 0;
	int T = (_h + A - 1) / A;
	
	return _A * T + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int hpY, atkY, defY;
	scanf("%d%d%d", &hpY, &atkY, &defY);
	int hpM, atkM, defM;
	scanf("%d%d%d", &hpM, &atkM, &defM);
	int h, a, d;
	scanf("%d%d%d", &h, &a, &d);

	int ans = 1e9;
	for (int _a = 0; _a < 250; _a++)
		for (int _d = 0; _d < 250; _d++)
		{
			int cost = _a * a + _d * d;
			if (cost >= ans)
				continue;

			int minHp = win(atkY + _a, defY + _d, hpM, atkM, defM);
			if (minHp == -1)
				continue;
			//fprintf(stderr, "%d, %d : %d\n", _a, _d, minHp);
			cost += h * max(0, minHp - hpY);
			ans = min(ans, cost);
		}
	printf("%d\n", ans);

	return 0;
}