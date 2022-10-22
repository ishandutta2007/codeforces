#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 20;

int n, k, nz;
ld my[Maxn];
ld prob[1 << Maxn], res[Maxn];

void Solve()
{
	prob[0] = 1;
	for (int i = 1; i < 1 << n; i++) if (__builtin_popcount(i) <= nz) {
		ld cur = 0, sum = 0;
		for (int j = 0; j < n; j++)
			if (i & 1 << j) {
				cur += my[j];
				sum += my[j] * prob[i ^ 1 << j];
			}
		prob[i] = sum / (1 - cur);
		if (__builtin_popcount(i) == nz)
			for (int j = 0; j < n; j++)
				if (i & 1 << j) res[j] += sum;
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		cin >> my[i]; nz += my[i] > 0;
	}
	nz = min(nz, k);
	Solve();
	for (int i = 0; i < n; i++)
		printf("%.12lf%c", double(res[i]), i + 1 < n? ' ': '\n');
	return 0;
}