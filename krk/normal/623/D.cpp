#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

const int Maxn = 105;

int n;
ld prob[Maxn];
ld win = 0.0;
ld kill[Maxn];
ld res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int p; scanf("%d", &p);
		prob[i] = ld(p) / 100;
		kill[i] = prob[i];
	}
	ld cur = 1.0l;
	for (int j = 0; j < n; j++)
		cur *= kill[j];
	res = n;
	for (int i = n; i < 1000000; i++) {
		res += 1 - cur;
		ld best = 1 + (1 - kill[0]) * prob[0] / kill[0];
		int bi = 0;
		for (int j = 1; j < n; j++) {
			ld cand = 1 + (1 - kill[j]) * prob[j] / kill[j];
			if (cand > best) best = cand, bi = j;
		}
		cur *= best;
		kill[bi] += (1 - kill[bi]) * prob[bi];
	}
	cout << fixed << setprecision(10) << res << endl;
	return 0;
}