#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 3005;

int n;
ld h[Maxn], r[Maxn], R[Maxn];
ld curh[Maxn];
ld res;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i] >> r[i] >> R[i];
		curh[i] = i? curh[i - 1]: 0;
		for (int j = 0; j < i; j++)
			if (r[i] >= R[j]) curh[i] = max(curh[i], curh[j] + h[j]);
			else if (r[j] <= R[i]) {
				if (r[i] >= r[j]) curh[i] = max(curh[i], (r[i] - r[j]) / (R[j] - r[j]) * h[j] + curh[j]);
				if (R[i] <= R[j]) curh[i] = max(curh[i], (R[i] - r[j]) / (R[j] - r[j]) * h[j] - h[i] + curh[j]);
				else curh[i] = max(curh[i], curh[j] + h[j] - (R[j] - r[i]) / (R[i] - r[i]) * h[i]);
			}
		res = max(res, curh[i] + h[i]);
	}
	printf("%.9lf\n", double(res));
	return 0;
}