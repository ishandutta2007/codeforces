#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 205;

int n;
ld p[Maxn];
ld dist[Maxn][Maxn];
ld cdist[Maxn][Maxn];

bool Enough(ld x)
{
	for (int i = 0; i <= 2 * n; i++)
		for (int j = 0; j <= 2 * n; j++)
			cdist[i][j] = dist[i][j] - x;
	for (int k = 0; k <= 2 * n; k++)
		for (int i = 0; i <= 2 * n; i++) if (cdist[i][k] >= -100.0l)
			for (int j = 0; j <= 2 * n; j++) if (cdist[k][j] >= -100.0l)
				cdist[i][j] = max(cdist[i][j], cdist[i][k] + cdist[k][j]);
	for (int i = 0; i <= 2 * n; i++)
		if (cdist[i][i] >= 0.0l) return true;
	return false;
}

int main()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
		cin >> p[i];
	fill((ld*)dist, (ld*)dist + Maxn * Maxn, -101.0l);
	for (int i = 0; i <= 2 * n; i++)
		for (int k = 0; k <= i && k <= n; k++) {
			int j = i - k + n - k;
			if (j <= 2 * n) dist[i][j] = p[k];
		}
	ld lef = 0.0l, rig = 1.0l;
	for (int i = 0; i < 32; i++) {
		ld mid = (lef + rig) / 2.0l;
		if (Enough(mid)) lef = mid;
		else rig = mid;
	}
	cout << fixed << setprecision(10) << lef << endl;
	return 0;
}